#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int C,T,n,m,res;
int h[N],e[N],ne[N],idx;
int dist[N];
int d[N];
bool st[N];
inline void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
	return ;
}
inline void dij(int st,int ed){
	memset(dist,0x3f,sizeof dist);
	dist[st]=0;
	queue<int> q;
	q.push(st);
	int minl=0x3f3f3f3f,cnt=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(t==ed){
			if(dist[ed]<=minl){
				if(minl==dist[ed]){
					++cnt;
				}
				else{
					minl=dist[ed];
					cnt=1;
				}
			}
			continue;
		}
		for(int i=h[t];~i;i=ne[i]){
			int j=e[i];
			if(dist[j]>=dist[t]+1){
				dist[j]=dist[t]+1;
				q.push(j);
			}
		}
	}
	if(cnt==2){
		++res;
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		res=0;
		memset(h,-1,sizeof h);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&d[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(d[i]-d[j])<=m){
					add(i,j);
					add(j,i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//检查 (i,j)是否成立
				dij(i,j); 
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
/*

*/
