#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,ans,n,m,d,q,s,e;
int w[1000005],k[1000005],vis[1000005];
int a[3005][3005],t[3005][3005];
int mp[3005][3005],ms[3005][305];
int dis[3005][3005];
vector<int> v[3005];
int mins(int aa,int bb){
	return aa<bb?aa:bb;
}
void bfs(){
	queue<int> que;
	que.push(s);
	int x;
	while(!que.empty()){
		x=que.front();
		que.pop();
		for(int i = 0;i < (int)v[x].size();i++){
			mp[s][v[x][i]]=mins(mp[s][v[x][i]],mp[s][x]+mp[x][v[x][i]]);
			if(!vis[v[x][i]]){
				vis[v[x][i]]=1;
				que.push(v[x][i]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	memset(mp,0x3f3f3f3f,sizeof mp);
	for(int i = 1;i <= n;i++){
		cin>>k[i];
		for(int j = 1;j <= k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j = 1;j <= k[i];j++){
			for(int g = j+1;g <= k[i];g++){
				if(!ms[a[i][j]][a[i][g]]){
					v[a[i][j]].push_back(a[i][g]);
					v[a[i][g]].push_back(a[i][j]);
				}
				mp[a[i][j]][a[i][g]]=mp[a[i][g]][a[i][j]]=min(mp[a[i][j]][a[i][g]],t[i][j]+t[i][g]);
				ms[a[i][j]][a[i][g]]=1;
				ms[a[i][g]][a[i][j]]=1;
			}
		}
		
	}
	while(q--){
		cin>>s>>e;
		for(int i = 0;i <= 500005;i++)vis[i]=0;
		ans=0x3f3f3f3f;
		vis[s]=1;
		bfs();
		printf("%lld\n",mp[s][e]+w[s]+w[e]);
	}
	return 0;
}
