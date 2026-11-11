#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,dis[500005],w[500005],k[505];
struct aaa{
	int a,t;
}a[505][300005];
vector<pair<int,int> > g[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdin);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0); 
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j].a >> a[i][j].t;
			g[a[i][j].a].push_back({i,a[i][j].t});
		}
	}
	int mm=m;
	priority_queue<pair<int,int> > p;
	for(int i=1;i<=q;i++){
		while(!p.empty()) p.pop();
		memset(dis,0x3f,sizeof(dis));
		bool book[50005]={};
		int x,y;
		cin >> x >> y;
		dis[x]=w[x];
		p.push({-dis[x],x});
		while(1){
			bool flag=true;
			for(int j=1;j<=m;j++)
				if(book[j]==false){
					flag=false;
					break;
				} 
			if(flag) break;
			int t1=p.top().first*-1,t2=p.top().second;
			p.pop();
			if(book[t2]) continue;
			book[t2]=true;
			for(int j=0;j<g[t2].size();j++){
				int id=g[t2][j].first,temp=g[t2][j].second;
				for(int ii=1;ii<=k[id];ii++){
					if(a[id][ii].a==t2) continue;
					dis[a[id][ii].a]=min(dis[a[id][ii].a]
					,t1+temp+a[id][ii].t);
					p.push({-dis[a[id][ii].a],a[id][ii].a});
				}
			}
		}
		cout << dis[y]+w[y] << "\n";
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
