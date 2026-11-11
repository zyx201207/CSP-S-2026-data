#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int maxx=INT_MAX;
int zd[maxn][30];
int ans;
int x,y;
//自己写的看不懂了qwqqwqqwqqwqwqwqwqwqwqwqwqwq
//我左边的人看起来很厉害的样子，一直在写字
//谁能关注我洛谷号 liuyichen20120807 球球了 
//666还有更正通知 
int way[505][maxn];
bool vis[maxn];
bool visway[505];
queue<pair<int,int>  > q;
int mm[maxn];
int c,n,m,d,qq;
int t[maxn][30];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>mm[i];
	}
	for(int i=1;i<=n;i++){
		cin>>way[i][0];
		for(int j=1;j<=way[i][0];j++){
			cin>>way[i][j];
			++zd[way[i][j]][0]=i;
			cin>>t[i][j];
		}
	}
	while(qq--){
		memset(vis,0,sizeof vis);
		memset(visway,0,sizeof visway);
		ans=maxx;
		cin>>x>>y;
		for(int i=1;i<=zd[x][0];i++){
			visway[zd[x][i]]=true;
			for(int j=1;j<=way[zd[x][i]][0];j++){
				q.push({way[zd[x][i]][j],mm[way[zd[x][i]][j]]+t[x][zd[x][i]]});
				vis[way[zd[x][i]][j]]=true;
				
			}
		}
		while(!q.empty()){
			int xx=q.front().first;
			int yy=q.front().second;
			q.pop();
			if(xx==y){
				ans=min(ans,yy);
				break;
			}
			for(int i=1;i<=zd[xx][0];i++){
					for(int j=1;j<=way[zd[xx][i]][0];j++){
						if(!vis[way[zd[xx][i]][j]]) q.push({way[zd[xx][i]][j],yy+mm[way[zd[xx][i]][j]]+t[xx][zd[xx][i]]});
					}
			}
		}
		cout<<ans<<'\n';
		while(!q.empty()) q.pop();
	}
	return 0;
	cout<<"我要AC！"; 
}
