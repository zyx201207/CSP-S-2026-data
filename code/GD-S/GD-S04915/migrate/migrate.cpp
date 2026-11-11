#include <bits/stdc++.h>
#define fo(i,l,r) for(int i(l); i<=(r); ++i)
#define fu(i,l,r) for(int i(l); i<(r); ++i)
#define fd(i,l,r) for(int i(l); i>=(r); --i)
#define File "migrate"
#define pb push_back
#define il inline
#define sz(x) (int((x).size()))
using namespace std;
using ll=long long;
const int N=2e6+5;
int tid,n;
ll d,a[N];
int p[N];
int f[N][2][3][2];
void solve() {
	cin>>n>>d;
	fo(i,1,n) cin>>a[i];
	p[0]=0,a[0]=a[1]-d-1;
	fo(i,1,n) {
		p[i]=p[i-1];
		while(p[i]<n&&a[p[i]+1]-a[i]<=d) ++p[i];
	}
	fd(i,n,1) fo(j,0,1) fo(k,0,2) fo(u,0,1) {
		f[i][j][k][u]=0;
		if(i==p[i]) continue;
		int L=i;
		if(u&&i>=2) L=max(L,p[i-2]);
		if(p[i]<=L) continue;
		int x=max(p[i-1]-max(L,i),0),y=max(0,p[i]-max(L,p[i-1]));
		f[i][j][k][u]=(j+k+1==2)*x+(j+1==2)*y;
		if(p[i-1]==p[i]) {
			if(j+k+1>2) continue;
			if(p[i]>L) {
				if(p[i]-i==1) f[i][j][k][u]+=f[p[i]][j+k][0][0];
				else if(p[i]-1<=L) f[i][j][k][u]+=f[p[i]][j+k][2][p[i]-i>2];
				else f[i][j][k][u]+=f[p[i]][j+k][j+k+1][p[i]-i>2];
			}
		} else {
			int t;
			if(p[i]-1==i) t=0;
			else if(p[i]-1<=L) t=2;
			else if(p[i]-1==p[i-1]) t=min(2,j+k+1);
			else t=j+1;
			f[i][j][k][u]+=f[p[i]][j][t][p[i]-i>2];
		}
	}
	ll ans=0;
	fo(i,1,n) ans+=f[i][0][0][0];
	cout<<ans<<'\n';
}
void clear() {

}
int main() {
	freopen(File".in","r",stdin);
	freopen(File".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int Tc;
	cin>>tid>>Tc;
	while(Tc--) solve(),clear();
	return 0;
}