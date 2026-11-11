#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll f=1,x=0; char ch;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-48;ch=getchar();}
	return f*x;
}
const ll N=5e5+5;
ll n,m;
ll a[N],b[N];
ll ans=0;
bool check(ll x,ll y){
	return (y-x+1)*(a[y])-(b[y]-b[x-1])<=m;
}
int main(){
	 freopen("crystal.in","r",stdin);
	 freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	n=read(),m=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	b[0]=a[0];
	for(ll i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	ll l=1,r=n,mid;
	for(ll R=1,l,r,mid;R<=n;R++){
		l=1,r=R;
		while(l<=r){
			mid=l+((r-l)>>1);
			if(check(mid,R)) ans=max(ans,R-mid+1),r=mid-1;
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}

