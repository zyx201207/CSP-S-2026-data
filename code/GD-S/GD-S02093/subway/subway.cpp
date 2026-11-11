#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
vector<pair<int,int> >e[N];
int w[N];int dd[N];
int num=0,ans=1e18;
void dfs(int st,int en){
	if(st==en){
		ans=min(ans,num);
		return;
	}
	num+=dd[st];
	for(auto i:e[st]){
		int v=i.first,t=i.second;
		num+=t;
		dfs(v,en);
		num-=t;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int xx,yy;
		cin>>xx>>yy;
		dd[xx]=yy;
		for(int j=2;j<=k;j++){
			int a,t;
			cin>>a>>t;
			e[xx].push_back({a,t});
		} 
	} 
	while(q--){
		int st,en;
		cin>>st>>en;
		ans=1e18;
		num=0;
		dfs(st,en);
		if(ans==1e18)ans=0;
		ans+=w[st];
		ans+=w[en];
		cout<<ans<<'\n';
	}
	return 0;
}
