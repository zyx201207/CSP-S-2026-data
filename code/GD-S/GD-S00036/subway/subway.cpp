#include<bits/stdc++.h>
using namespace std;
const int N=505,M=1005;
int c,n,m,d,q,cnt,w[M],k[N],g[N][N],a[N][M],t[N][M],id[N][M];
vector<int>bh[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			id[i][a[i][j]]=j;
			bh[a[i][j]].push_back(i);//µÚiÌõ±ß°üº¬a[i][j] 
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++)	g[i][i]=0;
	for(int pt=1;pt<=m;pt++){
		for(int i=1;i<=n;i++){
			if(a[i][1]!=pt&&a[i][2]!=pt)	continue;
			for(int j=1;j<=n;j++){
				if(a[j][1]!=pt&&a[j][2]!=pt)	continue;
				int t1=(a[i][1]==pt?t[i][1]:t[i][2]);
				int t2=(a[j][1]==pt?t[j][1]:t[j][2]);
				g[i][j]=g[j][i]=min(g[i][j],t1+t2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		int ans=1e9;
		for(int u:bh[x]){
			for(int v:bh[y]){
				ans=min(ans,g[u][v]+t[u][id[u][x]]+t[v][id[v][y]]+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1<=ki<=2
*/
