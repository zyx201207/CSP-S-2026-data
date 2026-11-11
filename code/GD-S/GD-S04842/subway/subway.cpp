#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int c,n,m,d,q;
int w[505]={},k[505]={}; 
vector<int> a[505],t[505];
//a[i][j]表示线路i第j站编号 
//t[i][j]表示线路i第j站走到用的时间 

vector<int> l[500005];//l[i]表示第i站有哪些线换乘 

bool vis[500005]={}; 
ll ans=LONG_LONG_MAX;

int find(int x,int line){
	for(int i=0;i<a[line].size();++i){
		if(a[line][i]==x){
			return i;
		}
	}
}

void dfs(int x,int line,ll tu,int y){//tu用了多长时间 
	//cout<<x<<" "<<line<<" "<<tu<<"\n";
	if(tu>=ans)return;//不可能了
	if(x==y){//到了 
		ans=min(ans,tu+t[line][find(x,line)]);
		return;
	}
	//现在在x点 line号线 
	//同线或者换乘
	for(auto to:a[line]){//同线换点 
		if(vis[to])continue;
		vis[to]=true;
		dfs(to,line,tu,y);
		vis[to]=false;
	} 
	for(auto used:l[x]){//同点换线 
		//正在x点line线，换used线 
		if(used==line)continue;
		int p1=find(x,line),p2=find(x,used);
		//cout<<t[line][p1]<<"\n"<<t[used][p2]<<"\n";
		dfs(x,used,tu+t[line][p1]+t[used][p2],y);
	}
}

void solve(int x,int y){
	ll time=w[x]+w[y];
	for(auto use:l[x]){
		vis[x]=true;
		dfs(x,use,t[use][find(x,use)],y);
		vis[x]=false;
	}
	cout<<ans+time<<"\n";
	ans=LONG_LONG_MAX;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa),t[i].push_back(tt);
			l[aa].push_back(i);
		}
	}
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		solve(x,y);
	}
	
	
	return 0;
}
