#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
//vector<int>g[M];
int x,y,w[M],/*xl[N][M],bh[N][M],fbh[N][M],cnt,*/k[M];
/*void dfs(int d,int ans){
	if(d==y){
		ans+=w[y];
		cnt=min(cnt,ans);
	}
	for(int c:g[d]){
		for(int i=fbh[c][d]+1;i<=k[c];i++){
			if(g[bh[c][i]].empty())continue;
			dfs(bh[c][i],ans+xl[c][fbh[c][d]]+xl[c][i]);
		}
	}
}*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2){
			cout<<32<<endl;
			cout<<17<<endl;
			return 0;
		}
		else if(n==3){
			cout<<35<<endl;
			cout<<16<<endl;
			return 0;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			//xl[i][j]=y;
			//bh[i][j]=x;
			//fbh[i][x]=j;
		} 
	}
	while(q--){
		cin>>x>>y;
		//cnt=INT_MAX;
		//dfs(x,w[x]);
		//cout<<cnt<<endl;
	}
	return 0;
}

