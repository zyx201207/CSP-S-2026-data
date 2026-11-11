#include<bits/stdc++.h>
#define fileio(name) (freopen(name".in","r",stdin),freopen(name".out","w",stdout))
#define MAXN 5005
#define NN 2000005
#define ll long long
using namespace std;
template<class T>inline void read(T& x){
	int f=1;char k=getchar();x=0;
	for(;k<'0'||k>'9';k=getchar())if(k=='-')f=-1;
	for(;'0'<=k&&k<='9';k=getchar())x=x*10+k-'0';
	x*=f;
}
int c,t,n;
ll d,x[NN];
int dist[MAXN][MAXN],cnt[MAXN][MAXN];
bool vis[MAXN];
bool de=true;
ll diff=0;
void bfs(int i){
	memset(vis,0,sizeof(vis));
	queue<pair<int,int>> q;
	dist[i][i]=0;
	cnt[i][i]=1;
	q.push({i,0});
	while(!q.empty()){
		int u=q.front().first;
		int len=q.front().second;
		q.pop();
		for(int v=u+1;v<=n;++v){
			if(x[v]>x[u]+d)break;
			if(vis[v]){
				if(len+1==dist[i][v])cnt[i][v]+=cnt[i][u];
				continue;
			}
			vis[v]=true;
			cnt[i][v]=cnt[i][u];
			dist[i][v]=len+1;
			dist[v][i]=len+1;
			q.push({v,len+1});
		}
	}
}
void subtask1(){
	int ans=0;
	for(int i=1;i<=n;++i){
		memset(dist[i],0,sizeof(dist[i]));
		memset(cnt[i],0,sizeof(cnt[i]));
	}
	for(int i=1;i<=n;++i){
		bfs(i);
	}
	
	for(int u=1;u<n;++u){
		for(int v=u+1;v<=n;++v){
//			printf("u%d v%d dist%d\n",u,v,dist[u][v]);
		}
	}
	for(int u=1;u<n;++u){
		for(int v=u+1;v<=n;++v){
			if(cnt[u][v]==2)ans++;
//			printf("u%d v%d %d\n",u,v,cnt[u][v]);
		}
	}
	printf("%d\n",ans);
}
void subtask2(){
	if(diff>=d){
		printf("0\n");
		return;
	}
	int num=diff/d,ans=0;
	for(int i=1;i<=n;++i){
		int k=(n-i)/(2*num-1);
		ans+=k;
	}
	printf("%d\n",ans);
}
int main(){
	fileio("migrate");
	read(c),read(t);
	while(t--){
		read(n),read(d);
		for(int i=1;i<=n;++i){
			read(x[i]);
			if(i<=2)diff=x[i]-x[i-1];
			else if(x[i]-x[i-1]!=diff)de=false;
		}
		if(n<=5000){
			subtask1();
			continue;
		}
		else if(de){
			subtask2();
			continue;
		}
	}
	return 0;
}
