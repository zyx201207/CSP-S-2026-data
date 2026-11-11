#include<iostream>
#include<vector>
using namespace std;

int cid,t,n,k,maxx,ans,fa[1005],deep[1005],mxd[1005],light[1005];
vector<int> v[1005];

void dfs1(int x,int from){//checkdis
	deep[x]=deep[from]+1;
	mxd[x]=min(mxd[x],deep[x]);
	for(int i=0;i<(int)v[x].size();i++){
		int too=v[x][i];
		if(too!=from) dfs1(too,x);
	}
}

int findfa(int x){
	if(fa[x]==x) return x;
	fa[x]=findfa(fa[x]);
	return fa[x];
}

void join(int x,int y){
	fa[findfa(x)]=findfa(y);
}

void dfs2(int x,int from){//merge
	for(int i=0;i<(int)v[x].size();i++){
		int too=v[x][i];
		if(too!=from){
			if(light[x]&&light[too]) join(x,too);
			dfs2(too,x);
		}
	}
}

void dfs(int x){
	if(x>k){
		maxx=0;
		for(int i=1;i<=n;i++) fa[i]=i,mxd[i]=2e9;
		dfs2(1,0);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(light[i]&&fa[i]==i) cnt++;
		}
		if(cnt>2) return;
		for(int i=1;i<=n;i++){
			if(light[i]){
				deep[0]=-1;
				mxd[i]=0;
				dfs1(i,0);
			}
		}
		for(int i=1;i<=n;i++) maxx=max(maxx,mxd[i]);
		ans=min(ans,maxx);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!light[i]){
			light[i]=1;
			dfs(x+1);
			light[i]=0;
		}
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cid>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		ans=2e9;
		for(int i=1;i<=n;i++) v[i].clear(),light[i]=0;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
