#include <bits/stdc++.h>
using namespace std;

int n;
long long d, x[2000100];

inline long long absl(long long x) {
	return (x>=0?x:-x);
}

namespace n3 {
	long long f[510][510];
	int l[510];
	long long pth[510][510];
	long long shortpath(int u, int v) {
		int ret=0;
		while(l[v]>u) {
			if(l[v]==v) {
				return 1e18;
			}
			ret++;
			v=l[v];
		}
		return ret+1;
	}
	inline void solve() {
		cin>>n>>d;
		if(n>1000) {
			cout<<"0\n";
			return;
		}
		for(int i=1;i<=n;++i) {
			cin>>x[i];
			for(int j=1;j<=i;++j) {
				if(absl(x[j]-x[i])<=d) {
					l[i]=j;
					break;
				}
			}
		}
		for(int i=1;i<=n;++i) {
			for(int j=i+1;j<=n;++j) {
				//i to j
				pth[i][j]=pth[j][i]=shortpath(i, j);
			}
		}
		for(int len=1;len<=n;++len) {
			for(int j=1;j+len-1<=n;++j) {
				if(absl(x[j+len-1]-x[j])<=d) {
					f[j][j+len-1]=f[j+len-1][j]=1;
					continue;
				}
				if(pth[j][j+len-1]==1e18) {
					f[j][j+len-1]=f[j+len-1][j]=0;
					continue;
				}
				for(int k=j+1;k<j+len-1;++k) {
					if(abs(x[j+len-1]-x[k])<=d && pth[j][k]+1==pth[j][j+len-1]) {
						f[j][j+len-1]+=f[j][k];
						f[j+len-1][j]+=f[j][k];
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i) {
			for(int j=i+1;j<=n;++j) {
				if(f[i][j]==2) ans++;
			}
		}
		for(int i=1;i<=n;++i) {
			l[i]=x[i]=0;
			for(int j=1;j<=n;++j) {
				f[i][j]=pth[i][j]=0;
			}
		}
		cout<<ans<<'\n';
	}
};

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin>>c>>t;
	while(t--) {
		n3::solve();
	}
	return 0;
}
