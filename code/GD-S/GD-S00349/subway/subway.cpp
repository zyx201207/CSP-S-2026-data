#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,m,n,d,q;
int k[500005];
int x,y;
int w[500005];
int a[505][50005];//线连接站台编号 
int ta[505][50005];//线连接站台距离 
vector<int> di[50005];//站台连接线编号 
vector<int> dt[50005];//站台连接线距离 
int vis[500005];
int minn=LLONG_MAX;
void dfs(bool ok,int nw,int t){
	if(ok==true&&nw==y){
		minn=min(minn,t);
		return;
	}
	if(t>10000000000){
		return;
	}
	if(ok){
		for(int i=0;i<di[nw].size();i++){
			if(!vis[di[nw][i]]){
				vis[di[nw][i]]=1;
				cout<<di[nw][i];
				dfs(0,di[nw][i],t+dt[nw][i]);
				vis[di[nw][i]]=0;
			}
		}
	}else{
		for(int i=1;i<=k[nw];i++){
			if(!vis[a[nw][i]]){
				vis[a[nw][i]]=1;
				cout<<a[nw][i];
				dfs(1,a[nw][i],t+ta[nw][i]);
				vis[a[nw][i]]=0;
			} 
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			if(i%2==1){
				cin>>a[i][j/2+1];
				di[a[i][j/2+1]].push_back(i);
			}else{
				cin>>ta[i][j/2];
				dt[a[i][j/2+1]].push_back(ta[i][j/2]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<di[i].size();j++){
			cout<<i<<di[i][j]<<dt[i][j]<<endl;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		minn=LLONG_MAX;
		dfs(1,x,w[x]);
		cout<<minn+w[y];
	}
	return 0;
}

