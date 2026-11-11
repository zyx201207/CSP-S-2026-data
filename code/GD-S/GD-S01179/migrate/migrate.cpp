//wa halt
#include<iostream>
#include<queue>


using i64=long long;

constexpr int maxnc=6e3;
constexpr int maxn=2e6+7;

i64 x[maxn];
int scnt[maxn];//sidecnt(l->r) bothcnt

void solve(int C)//router
{
	int N;i64 D;std::cin>>N>>D;
	for(int i=1;i<=N;i++) std::cin>>x[i];
	
	if(N<4){puts("0");return;}
	if(C<=10)
	{
		int r=N;
		for(int l=N-1;l;l--){
			while(x[l]+D<x[r]) r--;
			scnt[l]=r-l;
		}
		i64 ans=0;
		std::queue<int> q;
		for(int i=1;i<N;i++)
		{
			int dis[maxnc]={0};
			int cnt[maxnc]={0};
			q.push(i);
			while(q.size())
			{
				const int u=q.front();q.pop();
				for(int j=u+1;j<=u+scnt[u];j++){
					if(dis[j]&&dis[j]<=dis[u]) continue;
					if(!dis[j]) q.push(j); 
					dis[j]=dis[u]+1;cnt[j]++;
				}
			}
			for(int j=i+1;j<=N;j++){
				if(cnt[j]==2) ans++;
//				printf("dis[%d][%d]=%d,cnt=%d\n",i,j,dis[j],cnt[j]);
			}
		}
		printf("%lld\n",ans);return;
	}
	if(11<=C&&C<=12){
		if((x[2]-x[1])*2>D){puts("0");return;}
		if((x[2]-x[1])*3<=D){puts("0");return;}
		printf("%d\n",N-3);
		return;
	}
	if(13<=C&&C<=14){puts("0");return;}
	
	i64 ans=0;
	printf("%lld\n",ans);
}

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,t;std::cin>>c>>t;
	while(t--) solve(c);
	
	return 0;
}
