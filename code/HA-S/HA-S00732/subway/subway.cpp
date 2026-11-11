#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
struct sub{
	int a;
	ll t;
};
long long w[500005];
int k[505];
int sum[500005];
int cro[500005][25];
vector<sub> s[505];
bool vis[500005],line[505];
ll ans=0;
void dfs(int now,int to,ll w){
	if(vis[now])return;
	if(now==to){
		ans=min(ans,w);
		return;
	}
	vis[now]=1;
	for(int i=1;i<=sum[now];i++){
		if(line[cro[now][i]])continue;
		int xt;
		for(int j=0;j<s[cro[now][i]].size();j++){
			sub x=s[cro[now][i]][j];
			if(x.a==now){
				xt=x.t;
				break;
			}
		}
		for(int j=0;j<s[cro[now][i]].size();j++){
			sub x=s[cro[now][i]][j];
			line[cro[now][i]]=1;
			dfs(x.a,to,w+xt+x.t);
			line[cro[now][i]]=0;
		}
	}
	vis[now]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll x,y;
			cin>>x>>y;
			sub ne;
			ne.a=x;ne.t=y;
			s[i].push_back(ne);
			cro[x][++sum[x]]=i;
		}
	}
	for(int i=1;i<=q;i++){
		ans=LONG_LONG_MAX;
		int x,y;
		cin>>x>>y;
		dfs(x,y,w[x]+w[y]);
		cout<<ans<<'\n';
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
