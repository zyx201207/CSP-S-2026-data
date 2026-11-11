#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a;
		cin>>c;
		for(long long i=1;i<=a;i++){
			s+=c;
		}
	}
	long long cd=s.size();
	int mid=cd/2;
	
	int ans=0;
	if(cd%2==1){
		for(int i=0,j=cd-1;i<mid,j>mid;i++,j--){
			if(s[i]!=s[j]){
				ans++;
			}
		}
	}
	if(cd%2==0){
		for(int i=0,j=cd-1;i<mid,j>=mid;i++,j--){
			if(s[i]!=s[j]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
