#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=550,M=2e4+10;
int w[M],k[N],a[N][M],t[N][M],x[100010],y[100010],flag[N],ans=0x3f3f3f;
vector<pair<int,int> > v[N];
int vs[N];
void dfs(int now,int time,int fin){
	flag[now]=1;
	if(now==fin)ans=min(ans,time);
	for(int i=0;i<vs[now];i++){
		if(flag[v[now][i].first]==0){
			flag[v[now][i].first]=1;
			dfs(v[now][i].first,time+t[now][v[now][i].second]+t[v[now][i].first][v[now][i].second],fin);
			flag[v[now][i].first]=0;
		}
	}
	return;
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
		cin>>k[i];
		cin>>a[i][1]>>t[i][1];
		for(int j=2;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[a[i][j-1]].push_back(make_pair(a[i][j],i));
			vs[a[i][j-1]]++;
			v[a[i][j]].push_back(make_pair(a[i][j-1],i));
			vs[a[i][j]]++;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		dfs(x[i],0,y[i]);
		ans+=w[x[i]]+w[y[i]];
		cout<<ans<<endl;
	}
}
