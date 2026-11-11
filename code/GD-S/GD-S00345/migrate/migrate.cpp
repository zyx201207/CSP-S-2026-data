#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l;i <= (r);i ++)
#define per(i,l,r) for(int i = l;i >= (r);i --)
#define pii pair<int,int>
#define fi fisrt
#define se second
const int N=2e6+5,INF=4e18;
int c,n,k,a[N],pr[N],nx[N],ta[N],tb[N],L[N],R[N],val[N],mx[N],mi[N],d[N],f[N],t[N],ans;
void del(int x) {
	int ls=L[x],rs=R[x];
	L[rs]=ls,R[ls]=rs;
}
void Solve() {
	cin >> n >> k,ans=0,a[0]=-INF,a[n+1]=INF;
	rep(i,1,n) cin >> a[i];
	int l=0; rep(i,1,n) {
		while(l<i&&a[i]-a[l]>k) l++;
		pr[i]=l,ta[i]=0,L[i]=i-1,d[i]=i;
	}
	l=n; per(i,n,1) {
		while(l>i&&a[l]-a[i]>k) l--;
		nx[i]=l,tb[i]=0,R[i]=i+1,val[i]=1;
	} L[1]=1,R[n]=n,mx[0]=0,mi[n+1]=INF;
	rep(i,1,n) mx[i]=max(mx[i-1],nx[i]);
	per(i,n,1) mi[i]=min(mi[i+1],pr[i]);
//	rep(i,1,n) cout << i << " " << pr[i] << " " << nx[i] << "\n";
	rep(i,1,n) {
		int j=i;
		while(nx[j]!=j&&d[pr[nx[j]]]==i&&mx[i-1]<=i&&mi[nx[j]+1]>=nx[j]) {
			rep(_,j+1,nx[j]) del(_),val[_]=0,d[_]=i;
			val[i]+=nx[j]-j;
//			if(Ti==3)cout << i << " " << j << " " << nx[j] << " " << nx[nx[j]] << "\n";
			int z=nx[j];
			nx[i]=nx[nx[j]],j=z;
		}
		i=j;
	}
//	rep(i,1,n) cout << i << " " << d[i] << "\n";
	rep(i,1,n) if(d[pr[i]]==L[i]) pr[i]=d[pr[L[i]]];
	per(i,n,1) if(d[nx[i]]==R[i]) nx[i]=d[nx[R[i]]];
//	rep(i,1,n) cout << i << " " << pr[i] << " " << nx[i] << "\n";
	rep(i,1,n) if(d[pr[i]]!=i) ta[d[pr[i]]]+=val[i];
	rep(i,1,n) if(d[nx[i]]!=i) tb[d[nx[i]]]+=val[i];
	int x=1;
	while(R[x]!=x) ans+=ta[x]*tb[R[x]],x=R[x];
	cout << ans << "\n";
	return ;
}
void solve() {
	cin >> n >> k,ans=0;
	rep(i,1,n) cin >> a[i];
	int l=n; per(i,n,1) {
		while(l>i&&a[l]-a[i]>k) l--;
		nx[i]=l;
	}
	rep(i,1,n) {
		rep(j,0,i) t[j]=mx[j]=f[j]=0;
		int r=i; t[0]=1,f[i]=1;
//		cout << i << ":";
		per(j,i-1,1) {
//			if(a[j+1]-a[j]>k) break;
			while(r>nx[j]) t[mx[r]]-=f[r],r--; 
			mx[j]=mx[min(nx[j],i)]+1,f[j]=t[mx[j]-1],t[mx[j]]+=f[j];
//			cout << f[j] << " "; 
			if(f[j]==2) ans++;
		}
//		cout << "\n";
	}
	cout << ans << "\n";
	return ;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int dc=1,T=1,id;
	if(dc) cin >> c >> T;
	if(c<=10) rep(i,1,T) solve();
	else rep(i,1,T) Solve();
	return 0;
}

