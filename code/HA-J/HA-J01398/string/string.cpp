#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	int a[n+1];
	string b[n+1];
	string s;
	long long l=0;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		l+=a[i];
		for(int j=1;j<=a[i];++j){
			s+=b[i];
		}
		
	}
	long long ans=0;
	for(int i=0;i<l/2;++i){
		if(s[i]!=s[n-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
