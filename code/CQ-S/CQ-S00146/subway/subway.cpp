#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,n,m,d,_,a[500005],b[500005],ans,v[500005][505],dis[500005],vis[500005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
struct node{int dot,t;};
vector<node>p[505],e[505];
vector<int>p2[505];
bool cmp(node a,node b){return a.dot<b.dot;}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>_;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		for(int j=1;j<=b[i];j++){
			int x,y;
			cin>>x>>y;
			v[x][i]=1;
			p2[i].push_back(x);
			p[i].push_back({x,y});
		}
		sort(p[i].begin(),p[i].end(),cmp);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int s=1e9;
			for(int k=0;k<b[i];k++){
				int x=p[i][k].dot;
				int l=lower_bound(p2[j].begin(),p2[j].end(),x)-p2[j].begin();
				if(l==p2[j].size())continue;
				if(p2[j][l]!=x)continue;
				s=min(s,p[i][k].t+p[j][l].t);
			}
			e[i].push_back({j,s});
			e[j].push_back({i,s});
		}
	}
	while(_--){
		int x,y;
		cin>>x>>y;
		ans=1e9;
		for(int i=1;i<=n;i++){
			if(!v[x][i])continue;
			int s=0;
			for(int j=0;j<p[i].size();j++)if(p[i][j].dot==x)s=p[i][j].t;
			q.push({s,i});
			for(int j=0;j<=n;j++)dis[j]=1e9,vis[j]=0;
			dis[i]=s;
			while(!q.empty()){
				int o=q.top().first,o2=q.top().second;
				q.pop();
				if(v[y][o2]){
					int s=0;
					for(int j=0;j<p[o2].size();j++)if(p[o2][j].dot==y)s=p[o2][j].t;
					ans=min(ans,o+a[x]+a[y]+s);
					continue;
				}
				vis[o2]=1;
				for(int l=0;l<e[o2].size();l++){
					int w=e[o2][l].dot;
					if(vis[w])continue;
					if(dis[w]>=o+e[o2][l].t){
						dis[w]=o+e[o2][l].t;
						q.push({dis[w],w});
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
