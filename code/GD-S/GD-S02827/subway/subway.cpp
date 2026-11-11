#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,C,D,q;
ll dm[500011];
ll k;
//struct node {
//	ll x,y,op,h;
//};
//node a[500011];
ll a[1000][1000];
ll b[500011][30];
ll d[500011][30];
ll c[500011];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","W",stdout);
	cin>>C>>n>>m>>D>>q;
	for(int i=1; i<=m; i++) {
		cin>>dm[i];
	}
	ll x,y,op,iop=0;
	for(int i=1; i<=n; i++) {
		cin>>k;
		x=i;
		for(int j=1; j<=k; j++) {
			cin>>y>>op;
			c[y]++;
			b[y][c[y]]=op;
			d[y][c[y]]=i;
//			a[iop].x=y;
//			a[iop].y=x;
//			a[iop].op=op;
//			a[iop].h=h[y];
//			h[y]=iop;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			a[i][j]=1e18;
			if(i==j) {
				a[i][j]=0;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=c[i]; j++) {
			for(int k=1; k<=c[i]; k++) {
				if(j!=k) {
					a[d[i][j]][d[i][k]]=min(b[i][j]+b[i][k],a[d[i][j]][d[i][k]]);
				//	cout<<i<<" "<<d[i][j]<<" "<<d[i][k]<<endl;
				}
			}
		}
	}
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) {
//			cout<<i<<" "<<j<<" "<<a[i][j]<<" qq";
//		}
//		cout<<endl;
//	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	ll kl;
	for(int i=1; i<=q; i++) {
		cin>>x>>y;
		kl=1e18;
		for(int k=1; k<=c[x]; k++) {
			for(int j=1; j<=c[y]; j++) {
				kl=min(kl,b[x][k]+b[y][j]+dm[x]+dm[y]+a[d[x][k]][d[y][j]]);
			}
		}
		cout<<kl<<endl;
	}
	return 0;
}
