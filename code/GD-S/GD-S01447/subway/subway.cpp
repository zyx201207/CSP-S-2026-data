#include<bits/stdc++.h>
using namespace std;
const int N=5e5+550;
int c,n,m,d,q;
struct node{
	int v,c;
};
vector<node> g[N];
int ot[N],cnt;
int x,y;
int t[N];
long long ans[N];
map<pair<int,int>,int> mp;

void dfs(int s,int fa,int fc,long long sum){
//	cout<<s<<' '<<sum<<'\n';
	if(s==y){
		sum+=t[mp[{s,fc}]];
		if(ans[s]!=-1) ans[s]=min(ans[s],sum);
		else ans[s]=sum;
		return;
	}
	if(ans[s]!=-1&&sum>=ans[s]) return;
	
	if(ans[s]!=-1) ans[s]=min(ans[s],sum);
	else ans[s]=sum;
	
	for(int i=0;i<g[s].size();i++){
		if(g[s][i].v==fa) continue;
	//	cout<<s<<' '<<g[s][i].v<<'\n';
		if(s==x){
		//	cout<<t[mp[{s,g[s][i].c}]]<<'\n';
			dfs(g[s][i].v,s,g[s][i].c,t[mp[{s,g[s][i].c}]]);
		}else{
			if(g[s][i].c==fc){
				dfs(g[s][i].v,s,fc,sum);
			}else{
		//		cout<<s<<' '<<g[s][i].v<<' '<<t[mp[{s,g[s][i].c}]]<<' '<<t[mp[{s,fc}]]<<'\n';
				dfs(g[s][i].v,s,g[s][i].c,sum+t[mp[{s,g[s][i].c}]]+t[mp[{s,fc}]]);
			}
		}
	}
	return;
}

int main(){
	freopen("subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ot[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int s,j=1;j<=k;j++){
			cin>>s;
			g[s].push_back({i+500000,i});
			g[i+500000].push_back({s,i});
			
			if(!mp[{s,i}]) mp[{s,i}]=++cnt;
			cin>>t[mp[{s,i}]];
		}
	}
	while(q--){
		memset(ans,-1,sizeof(ans));
		cin>>x>>y;
		dfs(x,0,c,0);
		cout<<ans[y]+ot[x]+ot[y]<<'\n';
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

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
