#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
const long long M=1e18;
long long n,m,c,d,p,a[N],gs,v,u,f[N][550],c1,d1,ans;
vector<pair<long long,long long>>g[N];
vector<long long>xi[N];
void dfs(long long z,long long ss,long long lo){
	if(f[z][ss]<=lo)return;
	else f[z][ss]=lo;
	if(z==d1)return;
	for(auto v:xi[ss])if(v!=z)dfs(v,ss,lo);
	long long spp;
	
	for(auto v:g[z])if(v.first==ss){
		spp=v.second;break;
	}
	for(auto v:g[z]){
		long long ta=v.first,sp=v.second;
		if(ta==ss)continue;
		dfs(z,ta,sp+lo+spp);
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>gs;
		for(int j=1;j<=gs;j++){
			cin>>u>>v;xi[i].push_back(u);g[u].push_back({i,v});
		}
	}
	for(int i=1;i<=p;i++){
		memset(f,0x3f,sizeof(f));
		cin>>c1>>d1;
		for(auto v:g[c1])dfs(c1,v.first,v.second+a[c1]);
		ans=M;
		for(auto v:g[d1]){
			ans=min(ans,f[d1][v.first]+v.second+a[d1]);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
		

	return 0;
}
