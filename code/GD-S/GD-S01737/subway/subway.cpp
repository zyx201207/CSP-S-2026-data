#include<bits/stdc++.h>
using namespace std;
char buf[1<<25],*p1,*p2;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<25,stdin),p1==p2)?EOF:*p1++)
void read(int &x){
	x=0;
	char c=gc;
	for(;!isdigit(c);c=gc);
	for(;isdigit(c);c=gc) x=(x<<3)+(x<<1)+(c^48);
}
int c,n,m,d,q;
long long dis[505][505];
int w[500005];
vector<pair<int,long long> > graph[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1;i<=n;i++){
		int k;
		read(k);
		for(int j=1;j<=k;j++){
			int a,t;
			read(a),read(t);
			graph[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(pair<int,long long> u:graph[i]){
			for(pair<int,long long> v:graph[i]){
				if(u.first==v.first) continue;
				dis[u.first][v.first]=dis[v.first][u.first]=min(dis[u.first][v.first],u.second+v.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		read(x),read(y);
		long long ans=LLONG_MAX;
		for(pair<int,long long> i:graph[x]){
			for(pair<int,long long> j:graph[y]){
				ans=min(ans,dis[i.first][j.first]+i.second+j.second+w[x]+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
