#include <bits/stdc++.h>
using namespace std;
long long dis[550][550];
long long w[500050];
vector<pair<int,long long> >g[500050];
int main(){
	memset(dis,0x3f,sizeof(dis));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int xs=1;xs<=n;xs++){
		dis[xs][xs]=0;
	}
	for(int xs=1;xs<=m;xs++){
		scanf("%lld",&w[xs]);
	}
	for(int xs=1;xs<=n;xs++){
		int k;
		cin>>k;
		for(int xs2=1;xs2<=k;xs2++){
			int a;
			long long t;
			scanf("%d%lld",&a,&t);
			for(int xs3=0;xs3<(int)g[a].size();xs3++){
				 int ne=g[a][xs3].first;
				 dis[xs][ne]=min(dis[xs][ne],t+g[a][xs3].second);
				 dis[ne][xs]=min(dis[ne][xs],t+g[a][xs3].second);
			}
			g[a].push_back({xs,t});
		}
	}
	for(int p=1;p<=n;p++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				dis[x][y]=min(dis[x][y],dis[x][p]+dis[p][y]);
			}
		}
	}
	for(int xs=1;xs<=q;xs++){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=1e18;
		for(int xs2=0;xs2<(int)g[x].size();xs2++){
			for(int xs3=0;xs3<(int)g[y].size();xs3++){
				int ne1=g[x][xs2].first,dis1=g[x][xs2].second,ne2=g[y][xs3].first,dis2=g[y][xs3].second;
				ans=min(ans,dis[ne1][ne2]+dis1+dis2+w[x]+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
