#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;string s="";
ll cnt,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll num;char a;
		cin>>num>>a;cnt+=num;
		for(ll j=1;j<=num;j++){
			s+=a;
		}
	}
	if(n==1){
		cout<<0<<"\n";
		return 0;
	}
	for(ll i=0;i<cnt/2;i++){
		if(s[i]==s[cnt-i-1])continue;
		ans++;
	}cout<<ans<<"\n";
	return 0;
} 
