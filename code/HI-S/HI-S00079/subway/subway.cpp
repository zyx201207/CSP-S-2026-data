#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],r[100005][2],minn=1e18;
bool f[500005];
struct node{
	int a,t;
};
vector<node>v[1000];
vector<int>vv[100005];
struct dfs{
	int x,d;
};
vector<dfs>vc[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			v[i].push_back({x,y});
			vv[x].push_back(i);
		}
		if(c>=7&&c<=11){
			vc[v[i][1].a].push_back({v[i][2].a,v[i][1].t+v[i][2].t});
			vc[v[i][2].a].push_back({v[i][2].a,v[i][1].t+v[i][2].t});
		}
	}
	for(int i=1;i<=q;i++)cin>>r[i][0]>>r[i][1];
	if(c>=12&&c<=19){
	for(int i=1;i<=q;i++){
		memset(f,0,sizeof(f));
		struct zd{
			int u,ans;
		};
		queue<zd>u;
		u.push({r[i][0],w[r[i][0]]});
		f[r[i][0]]=1;
		while(!u.empty()){
			zd h=u.front();
			u.pop();
			if(h.u==r[i][1]){
				cout<<h.ans+w[h.u]<<endl;
				break;
			}
			for(auto k:vv[h.u]){
				for(auto j:v[k]){
					if(f[j.a]==0){
						f[j.a]=1;
						u.push({j.a,h.ans+2*j.t});
					}
				}
			}
		}
	}
    }else{
    	long long dp[10000][10000];
    	memset(dp,0x3f,sizeof(dp));
    	for(int i=1;i<=m;i++){
    		dp[i][i]=0;
    		for(auto j:vc[i])dp[i][j.x]=j.d;
		}
    	for(int k=1;k<=m;k++){
    		for(int i=1;i<=m;i++){
    			for(int j=1;j<=m;j++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
		for(int i=1;i<=q;i++){
			cout<<dp[r[i][0]][r[i][1]]<<endl;
		}
	}
	return 0;
} 
