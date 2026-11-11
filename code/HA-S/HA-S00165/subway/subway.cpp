#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=1e9;
int w[500005],k[505],f[500005];
int t[500005][25];
struct node{
	int id,line;
};
vector<node> v[500005];
set<int> st[505];
void dfs(int sum,int dq,int zd,int line){
	if(dq==zd){
		ans=min(ans,sum+t[zd][line]);
		return;
	}
	for(int i=0;i<v[dq].size();i++){
		if(f[v[dq][i].id]==0){
			int lsum=sum,lline=line;
			if(v[dq][i].line!=line){
				lsum+=t[dq][v[dq][i].line]+t[dq][line];
				lline=v[dq][i].line;
			}
			f[v[dq][i].id]=1;
			dfs(lsum,v[dq][i].id,zd,lline);
			f[v[dq][i].id]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i]; 
		int last=0,a;
		for(int j=1;j<=k[i];j++){
			cin>>a;
			cin>>t[a][i];
			st[a].insert(i);
			if(j!=1){
				v[last].push_back({a,i});
				v[a].push_back({last,i});
			}
			last=a;
		} 
	}
	for(int i=1;i<=q;i++){
		memset(f,0,sizeof(f));
        ans=1e9;
		int x,y;
		cin>>x>>y;
		f[x]=1;
		for(auto &j:st[x]) dfs(w[x]+t[x][j],x,y,j);
		cout<<ans+w[y]<<'\n';
	}
	return 0;
}
