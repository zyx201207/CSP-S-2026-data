#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string.h>
#include<vector>
#include<queue>
//#define in inline
#define int long long
//#define ll long long
#define N 500005
using namespace std;
inline int rd(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c^'0');
		c=getchar();
	}
	return x*f;
}
int c,n,m,d,qu;
int w[N];
struct quer{
	int x,y;
}query[100005];
inline bool cmp(quer x,quer y){return x.x<y.x;}
vector<pair<int,int>> e[N<<1];
vector<int> eh[N<<1];
vector<int> bel[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int dis[502][502];
int t[N][502];
bool is[N],ha[N],isdo[N];
inline void dij(int s){
	memset(is,false,sizeof(is));
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().first,v=q.top().second;
		q.pop();
		if(dis[s][u]<v)continue;
		if(is[u])continue;
		is[u]=true;
		for(auto i:e[u]){
			int f=i.first,k=i.second;
			if(dis[s][f]>dis[s][u]+k){
				dis[s][f]=dis[s][u]+k;
			}
			q.push({f,k});
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ha,false,sizeof(ha));
	memset(dis,0x3f,sizeof(dis));
	c=rd();n=rd();m=rd();d=rd();qu=rd();
	int cnt=0;
	for(int i=1;i<=m;i++)w[i]=rd();
	for(int i=1,k;i<=n;i++){
		k=rd();
		for(int j=1,a;j<=k;j++){
			a=rd(),t[j][i]=rd();
			bel[a].push_back(i);
			if(ha[a]){
				eh[a].push_back(i);
				cnt++;
			}
			ha[a]=true;
		}
	}
	for(int i=1;i<=m;i++){
		if(eh[i].empty())continue;
		for(int k=0;k<eh[i].size();k++){
			for(int j=0;j<eh[i].size();j++){
				if(j==k)continue;
				e[k].push_back({j,t[i][k]+t[i][j]});
				e[j].push_back({k,t[i][k]+t[i][j]});
			}
		}
	}
	int x,y,ans=-1;
	memset(isdo,false,sizeof(isdo));
	for(int i=1;i<=qu;i++){query[i].x=rd(),query[i].y=rd();}
	sort(query+1,query+qu+1,cmp);
	for(int i=1;i<=qu;i++){
		ans=1e18+7;
		x=query[i].x,y=query[i].y;
		for(int k:bel[x]){
			if(!isdo[k]){
				dij(k);
				isdo[k]=true;
			}
		}
		for(int k:bel[y]){
			for(int j:bel[x]){
				ans=min(ans,w[x]+w[y]+dis[k][j]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//找到换乘点，把所有非换乘站缩为一边;边权为上一换乘站入站路程加下一出站路程;
//从一线路换乘后不会再换回才保证最优 
