#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,l,t,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n;
	while(n--){
		ll x;char a;cin>>x>>a;
		for(int i=1;i<=x;i++)s+=a;l+=x;
	}
	t=l/2;if(l%2==0)t--;
	for(int i=0;i<=t;i++)if(s[i]!=s[l-i-1])ans++;cout<<ans;
	return 0;
}
