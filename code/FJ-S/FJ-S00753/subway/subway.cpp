#include<bits/stdc++.h>
using namespace std;
//#define int long long
//const int mod=;

int read() {
	int x=0,f=1,a=getchar();
	while (a<'0'||a>'9') {
		if (a=='-') f=-1;
		a=getchar();
	}
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x*f;
}

int c,n,m,d,q;
int w[500005];
vector<pair<int,int> >zx[500005];
long long v[505][505];

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	c=read(),n=read(),m=read(),d=read(),q=read();
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1; i<=m; i++) w[i]=read();
	//scanf("%d",&w[i]);
	for (int i=1; i<=n; i++) {
		int k=read();
	//	scanf("%d",&k);
		while (k--) {
			int x=read(),t=read();
		//	scanf("%d%d",&x,&t);
			zx[x].push_back({i,t});
		}
	}
	for (int i=1; i<=n; i++)
		for (int k=1; k<=n; k++)
			if (i!=k) v[i][k]=1e18;
	for (int i=1; i<=m; i++)
		for (int k_=0;k_<zx[i].size();k_++)
			for (int j_=k_+1;j_<zx[i].size();j_++) {
				pair<int,int>k=zx[i][k_],j=zx[i][j_];
				long long s=k.second+j.second;
				v[j.first][k.first]=v[k.first][j.first]=min(v[k.first][j.first],s);
			}
//	for (int i=1; i<=n; i++) {
//		for (int k=1; k<=n; k++) {
//			cout<<i<<' '<<k<<' '<<v[i][k]<<'\n';
//		}
//	}
	for (int i=1; i<=n; i++)
		for (int k=1; k<=n; k++)
			for (int j=k+1; j<=n; j++)
				v[j][k]=v[k][j]=min(v[k][j],v[k][i]+v[i][j]);
	while (q--) {
		int x=read(),y=read();
	//	scanf("%d%d",&x,&y);
		long long ans=1e18;
		for (pair<int,int> k:zx[x])
			for (pair<int,int> j:zx[y])
				ans=min(ans,v[k.first][j.first]+k.second+j.second);
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}

	return 0;
}
