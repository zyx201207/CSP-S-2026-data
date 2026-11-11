#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5005;
int O,T,N,D,Ans,vis[MAXN],a[MAXN];
inline int BFS1(int start,int end){
	for(int i=1;i<=N;++i)vis[i]=0;
	queue<pair<int,int> >q;
	q.emplace(0,start);
	while(!q.empty()){
		int d=q.front().first;
		int u=q.front().second;q.pop();
		if(u==end)return d;
		if(vis[u])continue;vis[u]=1;
		for(int i=1;i<=N;++i){
			if(!vis[i]&&abs(a[i]-a[u])<=D){
				q.emplace(d+1,i);
			}
		}
	}
	return -1;
}
inline int BFS2(int start,int end,int dep){
	int cnt=0;
	for(int i=1;i<=N;++i)vis[i]=0;
	queue<pair<int,int> >q;
	q.emplace(0,start);
	while(!q.empty()){
		int d=q.front().first;
		int u=q.front().second;q.pop();
		if(d==dep){
			if(u==end)cnt++;
			continue;
		}
		if(vis[u])continue;vis[u]=1;
		for(int i=1;i<=N;++i){
			if(!vis[i]&&abs(a[i]-a[u])<=D){
				q.emplace(d+1,i);
			}
		}
	}
	return cnt;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>O>>T;
	while(T--){
		cin>>N>>D;Ans=0;
		for(int i=1;i<=N;++i)cin>>a[i];
		for(int i=1;i<=N;++i){
			for(int j=i+2;j<=N;++j){
				int cnt=BFS1(i,j);
				if(cnt==-1)continue;
				if(BFS2(i,j,cnt)==2)Ans++;
			}
		}
		cout<<Ans<<"\n";
	}
	return 0;
}
//内存：672KB
//时间：O(N^2M)
//预估分数：0 
