#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,maxn=0,minn=LONG_LONG_MAX;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){cin>>a[i]>>c[i];minn=min(minn,a[i]);maxn=max(maxn,a[i]);}
	if(n==1){cout<<0;return 0;}
	if(n==2){
		if(c[1]==c[2]) cout<<0;
		else cout<<minn;
		return 0;
	}
	else{
		ll g=a[1];
		for(ll i=1;i<=n;i++) g=__gcd(g,a[i]);
		for(ll i=1;i<=n;i++) a[i]/=g;
		string s;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=a[i];j++) s+=c[i];
		}
		ll cnt=0,cnt1=0;
		if(s.size()%2==0){
			string s1=s.substr(0,s.size()/2);
			string s2=s1;
			reverse(s1.begin(),s1.end());
			s2+=s1;
			ll len=s.size();
			for(ll i=0;i<len;i++) if(s[i]!=s2[i]) cnt++;
			s1=s.substr(s.size()/2,s.size());
			s2=s1;
			reverse(s1.begin(),s1.end());
			s2=s1+s2;
			len=s.size();
			for(ll i=0;i<len;i++) if(s[i]!=s2[i]) cnt1++;
		}
		else{
			string s1=s.substr(0,s.size()/2);
			reverse(s1.begin(),s1.end());
			ll len=s.size();
			for(ll i=len/2+1;i<len;i++) if(s[i]!=s1[i-len/2]) cnt++;
			s1=s.substr(s.size()/2+1,s.size());
			reverse(s1.begin(),s1.end());
			len=s.size();
			for(ll i=0;i<len/2;i++) if(s[i]!=s1[i]) cnt1++;
		}
		cout<<min(cnt*g,cnt1*g);
	}
	return 0;
}
/*
 * abcdef abccba
 * abbcca abbbba
 * abc 1
 * */
