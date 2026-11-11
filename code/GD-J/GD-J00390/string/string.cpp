#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[200010];
char c[200020];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int r=0,l=s.size();
	int mid=(r+l-1)/2;
	r=mid-1;
	l=mid+1;
	while(r>=0&&l<=s.size()){
		if(s[r]==s[l]){
			r-=1;
			l+=1;
		}
		else{
			ans++;
			r-=1;
			l+=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
