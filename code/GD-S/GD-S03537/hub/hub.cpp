#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mem(a,b) memset(a,b,sizeof(a))
#define For(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
#define Gor(i,a,b) for (int (i)=(a);(i)>=(b);(i)--)
using namespace std;
const int N=1e6+10;
int C,T,n,k,dep[N][2],d[N][2],vis[N],ans,dis[N];
vector<int>e[N];
priority_queue<pair<int,int> >q;
queue<int>q2;
void dfs(int x,int fa,int t){
	d[x][t]=dep[x][t];
	for (int y:e[x]){
		if (y==fa) continue;
		dep[y][t]=dep[x][t]+1;
		dfs(y,x,t);
		d[x][t]=max(d[x][t],d[y][t]);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	IOS
	cin >> C >> T;
	while (T--){
		For(i,1,n) e[i].clear();
		cin >> n >> k;
		For(i,2,n){
			int x,y;
			cin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		ans=n-2;
		For(i,1,n){
			For(j,1,n){
				if (i==j) continue;
				while (!q.empty()) q.pop();
				while (!q2.empty()) q2.pop();
				dep[i][0]=dep[j][1]=0;
				For(l,1,n) vis[l]=0,d[i][0]=d[i][1]=0;
				vis[i]=vis[j]=1;
				dfs(i,0,0);
				dfs(j,0,1);
				q.push({min(d[i][0],d[i][1]),i});
				q.push({min(d[j][0],d[j][1]),j});
				For(l,1,k-2){
					int x=q.top().second;
					q.pop();
					vis[x]=1;
					for (int y:e[x]){
						if (vis[y]) continue;
						q.push({min(d[y][0]-dep[x][0],d[y][1]-dep[x][1]),y});
					}
				}
				For(l,1,n){
					if (vis[l]) dis[l]=0,q2.push(l);
				}
				int res=0;
				while (!q2.empty()){
					int x=q2.front();
					q2.pop();
					for (int y:e[x]){
						if (!vis[y]){
							dis[y]=dis[x]+1;
							vis[y]=1;
							res=max(res,dis[y]);
							q2.push(y);
						}
					}
				}
				ans=min(ans,res);
			}
		}
		cout << ans << '\n';
	}
}
