#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[1000000],p[505][505],way[505][505];
struct t{
	int f,s;
};
vector<t> r[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(p,0x3f,sizeof(p));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
 	int to,ti;
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++){
			scanf("%d%d",&to,&ti);
			r[to].push_back({i,ti});
		}
	}
	for(int i=1;i<=m;i++){
		int l=r[i].size();
		for(int j=0;j<l-1;j++){
			for(int k=j+1;k<l;k++){
				p[r[i][j].f][r[i][k].f]=
				p[r[i][k].f][r[i][j].f]=
				min(p[r[i][j].f][r[i][k].f],r[i][j].s+r[i][k].s);
			}
		}
	}
	for(int i=1;i<=n;i++)p[i][i]=0;
	int s,e,ans=0,cnt=0,dis[505][505];
	bool f[505];
	memset(dis,0x3f,sizeof(dis));
	for(int k=1;k<=n;k++){
	memset(f,0,sizeof(f));
		dis[k][k]=0;
		while(cnt<=n){
			cnt++;
			int mini=1061109567,mi;
			for(int i=1;i<=n;i++)
				if(!f[i]&&mini>dis[k][i]){
					mini=dis[k][i];
					mi=i;
				}
				f[mi]=1;
			for(int i=1;i<=n;i++){
				if(f[i])continue;
				dis[k][i]=min(dis[k][i],p[i][mi]);
			}
		}
	}
	while(q--){
		scanf("%d%d",&s,&e);
		int ans=50000005;
		for(int j=1;j<=m;j++){
			for(int i=1;i<=r[j].size();j++){
				for(int k=1;k<=m;k++){
					for(int v=1;v<=r[k].size();v++)
						ans=min(ans,w[s]+w[e]+r[j][i].s+r[k][v].s+dis[r[j][i].f][r[k][v].f]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
