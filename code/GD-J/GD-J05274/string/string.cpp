#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[200010];
char c[200010];
bool check(int x){
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			if(x>0)
				x--;
			else
				return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
//	cout<<s;
	int l=0;
	int r=s.size();
	
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<l<<'\n';
	return 0;
}

