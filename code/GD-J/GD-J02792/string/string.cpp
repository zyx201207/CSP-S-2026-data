#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=0;string S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;++i){
		ll t;char temp;
		cin>>t>>temp;
		for(int j=1;j<=t;++j)
			S+=temp;
	}
	ll l=S.size();
	
	for(int i=0;i<(n/2+1);++i){
		if(S[i]==S[l-i]){
			continue;
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
