#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],x,y,ans;
vector<long long> sub[1000010];
map<pair<int,int>,long long> mp,jl;
void dfs(int t,long long cnt){
	pair<int,int> ty,xy;
	ty.first=t;
	ty.second=y;
	xy.first=x;
	xy.second=y;
	if(jl[ty]!=0){
		ans=min(ans,jl[ty]+cnt);
		jl[xy]=ans;
	}if(t==y){
		ans=min(ans,cnt);
		jl[xy]=ans;
		return;
	}for(auto i:sub[t]){
		pair<int,int> xi,ti,ix;
		ti.first=t;
		ti.second=i;
		xi.first=x;
		xi.second=i;
		ix.first=i;
		ix.second=x;
		if((jl[xi]==0&&i!=x)||jl[xi]>cnt+mp[ti]){
			jl[xi]=cnt+mp[ti];
			jl[ix]=cnt+mp[ti];
			dfs(i,cnt+mp[ti]);
		}
	}
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			sub[i+m].push_back(a);
			pair<int,int> pa;
			pa.first=i+m;
			pa.second=a;
			mp[pa]=t;
			sub[a].push_back(i+m);
			pa.first=a;
			pa.second=i+m;
			mp[pa]=t;
		}
	}while(q--){
		cin>>x>>y;
		ans=5e18+10;
		dfs(x,0);
		cout<<ans+w[x]+w[y]<<'\n';
	}return 0;
}
