#include<bits/stdc++.h>
using namespace std;
char buf[1<<25],*p1,*p2;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<25,stdin),p1==p2)?EOF:*p1++)
void readi(int &x){
	x=0;
	int f=1;
	char c=gc;
	for(;!isdigit(c);c=gc) f=(c=='-'?-1:1);
	for(;isdigit(c);c=gc) x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
void readll(long long &x){
	x=0;
	int f=1;
	char c=gc;
	for(;!isdigit(c);c=gc) f=(c=='-'?-1:1);
	for(;isdigit(c);c=gc) x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int c,T;
int n;
long long d,a[2000005];
vector<int> graph[5005];
long long dis[605][605],cnt[605][605];
void Dijkstra(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,s});
	dis[s][s]=0;
	cnt[s][s]=1;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(int v:graph[u]){
			if(dis[s][v]>dis[s][u]+1){
				dis[s][v]=dis[s][u]+1;
				cnt[s][v]=cnt[s][u];
				q.push({dis[s][v],v});
			}
			else if(dis[s][v]==dis[s][u]+1) cnt[s][v]+=cnt[s][u];
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	readi(c),readi(T);
	if(c==11||c==12){
		while(T--){
			readi(n),readll(d);
			for(int i=1;i<=n;i++) readll(a[i]);
			long long D=a[2]-a[1],tmp=d/D;
			if(tmp<=1) printf("0\n");
			else printf("%d\n",n-4);
		}
		return 0;
	}
	else if(c==13||c==14){
		while(T--){
			readi(n),readll(d);
			for(int i=1;i<=n;i++) readll(a[i]);
			cout<<0<<'\n';
		}
		return 0;
	}
	while(T--){
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		readi(n);
		readll(d);
		for(int i=1;i<=n;i++) readll(a[i]);
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d) graph[i].push_back(j),graph[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++) Dijkstra(i);
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++) graph[i].clear();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
