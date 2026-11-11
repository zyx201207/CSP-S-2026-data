#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll f[N],g[N],n,d,a[N],b[N],w[N],fa[N];
//struct FenwickTree{
//	ll w[N];
//	void change(int x,ll y){
//		while(x<=n)
//			w[x]+=y,
//			x+=lowbit(x);
//	}
//	ll query(int x){
//		ll res=0;
//		while(x)
//			res+=w[x],x-=lowbit(x);
//		return res;
//	}
//	void clear(){
//		for(int i=0;i<=n;i++) w[i]=0;
//	}
//}G;
void solve(){
	ll ans=0;
	cin>>n>>d;
//	w.clear();
//	F.clear();
	for(int i=1;i<=n;i++) cin>>a[i];
//	a[n+1]=8e18;
	int j=1,k=1;
	a[0]=-8e18;
//	if(a[n]<a[n-1]+d) a[n+1]=a[n-1]=d;
//	else
	a[n+1]=8e18;
	for(int i=1;i<=n;i++){
		f[i]=0;
		while(a[j]+d<a[i]) j++;
		while(a[k]+d<a[i+1]) k++;
		f[i]=(j!=k)*f[j]+1;
//		cout<<k<<' '<<j<<' '<<f[i]<<' '<<k-j<<'\n';
//		f[i]+=k-j;
//		F.change(i,f[i]);
	}
	j=k=n;
	for(int i=n;i>=1;i--){
		g[i]=0;
		while(a[j]-d>a[i]) j--;
		while(a[k]-d>a[i-1]) k--;
		fa[i]=j;
//		if(j>fa[])
		g[i]=(j!=k)*g[j]+1;
//		G.change(i,g[i]);
//		cout<<i<<' '<<g[i]+1<<' '<<w.query(n)<<'\n';
	}
	for(int i=1;i<=n;i++) w[i]=w[i-1]+g[i];
//	for(int i=1;i<=n;i++)
//		cout<<f[i]<<' ';
//	cout<<'\n';
//	for(int i=1;i<=n;i++)
//		cout<<g[i]<<' ';
//	cout<<'\n';
	j=1;
	int ly=0;
	for(int i=1;i<=n;i++){
		while(a[i]+d>=a[j+1]) j++;
		if(j-i<=1) continue;
		int y=upper_bound(a+1,a+1+n+1,a[j-1]+d)-a-1,
			x=upper_bound(a+1,a+1+n+1,a[j-2]+d)-a-1;
//		cout<<i<<' '<<x<<' '<<y<<' '<<f[i]<<' '<<w.query(y)-w.query(x)<<'\n';
//		cout<<a[i]<<' '<<a[j-2]<<' '<<a[j-1]<<' '<<a[x]<<' '<<a[y]<<' '
//		<<g[y]<<' '<<(f[i])*(g[y]+y-x-1)<<'\n';
//		cout<<ly<<' '<<y<<'\n';
		if(x!=y)
			if(y>ly)
				ans+=(f[i])*(g[y]+y-x-1);
			else
				ans+=(g[y]+y-x-1);
		ly=y;
	}
	cout<<ans<<'\n';
}
int c,T;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	 freopen("migrate.in","r",stdin);
	 freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
//inf
