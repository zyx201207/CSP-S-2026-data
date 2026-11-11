#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=20005;
int c,n,m,D,q,w[M],vis[M],vis2[N],k[M],d[M],a[M][N],t[M][N];
vector<int>v[M];
int dij(int s,int tt){
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	memset(vis2,0x3f,sizeof(vis2));
	d[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int k2=q.front();
		q.pop();
		if(vis[k2])continue;
		vis[k2]=1;
		if(k2==tt)return d[k2];
		int l=v[k2].size();
		for(int i=0;i<l;i++){
			int T=v[k2][i];
			if(vis2[T]<=d[k2])continue;
			vis2[T]=d[k2];
			for(int j=1;j<=k[T];j++){
				int t2=a[T][j];
				if(vis[t2])continue;
				if(d[t2]>d[k2]+t[k2][T]+t[t2][T]){
					d[t2]=d[k2]+t[k2][T]+t[t2][T];
					q.push(t2);
				}
			}
		}
	}
	return d[tt];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[a[i][j]][i];
			v[a[i][j]].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dij(x,y)<<'\n';
	}
	return 0;
}
