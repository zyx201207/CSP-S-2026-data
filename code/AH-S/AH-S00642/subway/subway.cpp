#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=1e3+10;
int a[M],d[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,l,q;
	cin>>c>>n>>m>>l>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	memset(d,0x3f,sizeof(d));
	while(n--){
		int t;
		cin>>t;
		m++;
		while(t--){
			int u,w;
			cin>>u>>w;
			d[u][m]=d[m][u]=w;
		}
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++){
			if(d[k][i]==0x3f3f3f3f)continue;
			for(int j=1;j<=m;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<d[s][t]+a[s]+a[t]<<'\n';
	}
}
