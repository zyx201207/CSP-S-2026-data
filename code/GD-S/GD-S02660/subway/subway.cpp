#include<bits/stdc++.h>
using namespace std;
int k[510];
long long w[500010],dis[510][510];
vector<pair<int,long long> >G[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=m;i++)
		scanf("%lld",w+i);//口到厅 
	for(int i=1;i<=n;i++){
		scanf("%d",k+i);
		dis[i][i]=0;
		for(int j=1;j<=k[i];j++){
			int sta;
			long long t;
			scanf("%d%lld",&sta,&t);
			G[sta].emplace_back(make_pair(i,t));//sta厅到i的时间为t 
		}
	}
	for(int i=1;i<=m;i++){
		if(G[i].size()>1){
			for(int j=0,siz=G[i].size();j<siz-1;j++)
				for(int k=j+1;k<siz;k++){
					int lin1=G[i][j].first,lin2=G[i][k].first;
					long long tim1=G[i][j].second,tim2=G[i][k].second;
					if(lin1>lin2)
						swap(lin1,lin2);
					if(dis[lin1][lin2]>=0x3f3f3f3f3f3f3f3f)
						dis[lin1][lin2]=tim1+tim2;
					else
						dis[lin1][lin2]=min(dis[lin1][lin2],tim1+tim2);
					dis[lin2][lin1]=dis[lin1][lin2];
				}
		}
	}
#ifdef DEBUG_
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k)
				for(int j=1;j<=n;j++)
					if(i!=j&&k!=j)
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
#else
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k&&dis[min(i,k)][max(i,k)]<0x3f3f3f3f3f3f3f3f)
				for(int j=1;j<=n;j++)
					if(j!=k&&i!=j&&dis[min(j,k)][max(j,k)]<0x3f3f3f3f3f3f3f3f)
						if(dis[min(i,j)][max(i,j)]>=0x3f3f3f3f3f3f3f3f)
							dis[min(i,j)][max(i,j)]=dis[min(i,k)][max(i,k)]+dis[min(j,k)][max(j,k)];
						else
							dis[min(i,j)][max(i,j)]=min(dis[min(i,j)][max(i,j)],dis[min(i,k)][max(i,k)]+dis[min(j,k)][max(j,k)]);
#endif
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0,sizx=G[x].size();j<sizx;j++)
			for(int k=0,sizy=G[y].size();k<sizy;k++){
				int lin1=G[x][j].first,lin2=G[y][k].first;
				long long tim1=G[x][j].second,tim2=G[y][k].second;
				if(lin1>lin2)
					swap(lin1,lin2);
				ans=min(ans,dis[lin1][lin2]+tim1+tim2);
			}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
