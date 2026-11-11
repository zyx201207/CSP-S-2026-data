#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define fi first
#define se first
using namespace std;
const int N=5e5+10;
const int mod=998244353;
const ll inf=0x3f3f3f3f3f3f3f3f;
int maxx=N-10;
ll n,m,ans;
ll a[N];
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
ll ppow(ll n,ll m){ll s=1;while(m){if(m&1)s=(s*n)%mod;n=(n*n)%mod;m>>=1;}return s;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	ll l=1,cnt=0;
	a[0]=a[1];
	for(int r=1;r<=n;r++){
		ll now=0;
		cnt+=(a[r]-a[r-1])*(r-l);
		while(l<r&&cnt>m){
			cnt-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
