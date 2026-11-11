#include<bits/stdc++.h>
#define ll long long
#define ri register int
#define ld long double
#define stg string
#define Cn const
using namespace std;
ll read() {
	ll r=0,fl=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') fl=-fl;c=getchar();}
	while(c>='0'&&c<='9') {r=(r<<3)+(r<<1)+(c^48);c=getchar();}
	return r*fl;
}
ll Max(ll a,ll b) {return a>b?a:b;}
ll Min(ll a,ll b) {return a<b?a:b;}
Cn ld eps=1e-9;
Cn ll Inf=1e18;
Cn int N=5e5+5;
ll n,m,a[N],s[N],ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll l=1;
	for(ll i=1;i<=n;i++) {
		while(l<i&&a[i]*(i-l+1)-(s[i]-s[l-1])>m) l++;
		ans=Max(ans,i-l+1);
	}
	cout<<ans;
}

