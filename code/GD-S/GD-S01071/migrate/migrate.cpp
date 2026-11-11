#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T;
int n;
ll d;
ll zb[2000005];
vector<int>v[5005];
int dis[5005],bz[5005];
int cnt[5005];
const int inf=(1e9);
queue<int>q;
int dij(int x){
	for(int i=1;i<=n;i++) dis[i]=inf,bz[i]=0,cnt[i]=0;
	dis[x]=0;
	q.push(x);
	cnt[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
//		cout<<u<<endl<<endl;
		bz[u]=1;
		for(auto k:v[u]){
			if(bz[k]) continue;
			if(dis[k]>dis[u]+1){
				dis[k]=dis[u]+1;
				cnt[k]=cnt[u];
				q.push(k);
			}
			else if(dis[k]==dis[u]+1) cnt[k]+=cnt[u];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(cnt[i]==2) ans++;
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate1.in","r",stdin);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&zb[i]);
		if(n<=5000){
			for(int i=1;i<=n;i++) v[i].clear();
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(zb[j]-zb[i]<=d){
						v[i].push_back(j);
						v[j].push_back(i);
					}
				}
			}
//			cout<<1<<endl<<endl;
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=dij(i);
			}
			printf("%d\n",ans/2);			
		}	
	}
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

