//GZ_S00159  安顺市第二高级中学 郑焕恒

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define int long long

const int M=2e6+7;
const int N=5007;
using namespace std;
int c,t;
int n,d;

vector<int>al[M];
int dis[M],vis[M];
int ji[M];
void dfs(int u,int tim){
	vis[u]=tim;
	int len=al[u].size();
	for(int i=0;i<len;i++){
		int v=al[u][i];
		//if(vis[v])continue;
		//if(v==u)continue;
		int zhi=dis[u]+1;
		if(zhi==dis[v]){
			ji[v]+=ji[u];
		}else if(zhi<dis[v]){
			dis[v]=zhi;
			ji[v]=ji[u];
		}//cout<<ji[v]<<'\n';
		dfs(v,tim);
		
	}
}
struct eg{
	int val,idx;
}w[M];
int cmp(const eg&a,const eg&b){
	return a.val<b.val;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w,",stdout);
	//freopen("t11.in","r",stdin);
	//freopen("t11.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&w[i].val);
			w[i].idx=i;
			al[i].clear();
			vis[i]=0;
			ji[i]=0;
		}
		sort(w+1,w+1+n,cmp);
        for(int i=1;i<n;i++){
        	for(int j=i+1;j<=n;j++){
        		if(w[j].val-w[i].val<=d){
        			al[w[i].idx].push_back(w[j].idx);
        			//al[w[i].idx].push_back(w[j].idx);
				}
			}
		}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			fill(dis+1,dis+1+n,1e18);
			dis[i]=0;
			ji[i]=1;
			dfs(i,i);
			for(int j=1;j<=n;j++){
			    if(ji[j]==2){
					ans++;
			    }//cout<<ji[n]<<'\n';
			}
		}
		printf("%lld\n",ans);	
	}
	return 0;
}/*
2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
???????????????
*/