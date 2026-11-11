#include<bits/stdc++.h>
#define int long long
using namespace std;
struct qq{
	int x,c;
	bool operator < (const qq & x)const{
		return x.c<c;
	}
};
priority_queue<qq> q;
int ne[500005];
vector<qq> ed[500505];
vector<qq> ed1[500505];
int dis[500505];
int vis[500505];
int dis1[505][505];
int aa[505][505];
signed main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	int cc,n,m,d,qqq;
	cin>>cc>>n>>m>>d>>qqq;
	for(int i=1;i<=m;i++)cin>>ne[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int uu,vv;
			cin>>uu>>vv;
			ed1[uu].push_back({i+m,vv});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)aa[i][j]=7e18;
	for(int i=1;i<=m;i++){
		for(qq c:ed1[i])for(qq v:ed1[i]){
			if(c.x==v.x)continue;
			aa[c.x-m][v.x-m]=aa[v.x-m][c.x-m]=min(aa[c.x-m][v.x-m],c.c+v.c);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(aa[i][j]>=4e18)continue;
			ed[i+m].push_back({j+m,aa[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m+1;j<=n+m;j++)dis[j]=7e18,vis[j]=0;
		dis[i+m]=0;
		q.push({i+m,0});
		while(!q.empty()){
			qq c=q.top();
			q.pop();
			if(vis[c.x])continue;
			vis[c.x]=1;
			for(qq v:ed[c.x]){
				if(dis[v.x]>v.c+c.c){
					dis[v.x]=v.c+c.c;
					q.push({v.x,dis[v.x]});
				}
			}
		}
		for(int j=1;j<=n;j++)dis1[i][j]=dis[j+m];
	}
	while(qqq--){
		int x,y;
		cin>>x>>y;
		int ans=7e18;
		for(qq c:ed1[x])for(qq v:ed1[y])ans=min(ans,dis1[c.x-m][v.x-m]+c.c+v.c);
		cout<<ans+ne[x]+ne[y]<<endl;
	}
}
