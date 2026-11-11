#include<bits/stdc++.h>
#define int long long
#define N 500005
#define M 10000000000000005
using namespace std; 
int c,n,m,k[550],d,q,x,y,ans,w[N],v[505],vis[505];
//vector<int> a[550],t[550];
vector<int> b[N],e[N];
unordered_map<int,int> mp[550];
signed main(){
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,aa,tt;j<=k[i];j++) cin>>aa>>tt,b[aa].push_back(i),e[aa].push_back(tt);
	}
	for(int i=1;i<=m;i++)
		for(int j=b[i].size()-1;j>=0;j--)
			for(int k=j-1;k>=0;k--){
				if(mp[b[i][j]][b[i][k]]==0){
					mp[b[i][j]][b[i][k]]=mp[b[i][k]][b[i][j]]=e[i][j]+e[i][k];
				}else{
					mp[b[i][j]][b[i][k]]=min(mp[b[i][j]][b[i][k]],e[i][j]+e[i][k]);
					mp[b[i][k]][b[i][j]]=min(mp[b[i][k]][b[i][j]],e[i][j]+e[i][k]);
				}
			}
	while(q--){
		cin>>x>>y;
		ans=M;
		priority_queue<pair<int,int> > p;
		pair<int,int> f;
		int st,nd;
		memset(v,0x62,sizeof(v));
		memset(vis,0,sizeof(vis));
		for(int i=b[x].size()-1;i>=0;i--)	p.push({0-e[x][i],b[x][i]}),v[b[x][i]]=e[x][i];
		while(!p.empty()){
			f=p.top();p.pop();
			st=0-f.first;nd=f.second;
			if(st>=v[nd]&&vis[nd]){continue;}
			vis[nd]=1;
			for(auto j: mp[nd]){
				if(v[j.first]>st+j.second){
					v[j.first]=st+j.second;vis[j.first]=0;
					p.push({0-(st+j.second),j.first});
				}
			}
		}for(int j=b[y].size()-1;j>=0;j--)
			ans=min(ans,v[b[y][j]]+e[y][j]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
