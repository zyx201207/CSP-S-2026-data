//GZ-S00352 遵义市第十二中学  李承昊 
#include <bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
long long C,n,m,D,Q,w[M],t,a[25][N],k[M],ans;
bool vis[M];
vector<int>e[N];
void BFS(int x,int y){
	int ans=0;
	queue<int>q;
	q.push(x);
	cout<<ans<<endl;
	while(!q.size()){
		int u=q.front();
		q.pop();
		if(u==y) break;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=1;i<=e[u].size();i++){
			q.push(e[u][i]);
			ans++;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k[i];j++)
			for(int k1=1;k1<=k[i];k1++) if(j!=k[i]) e[a[i][j]].push_back(a[i][k1]);
	while(Q--){
		for(int i=1;i<=m;i++) vis[i]=0;
		ans=0;
		int x,y;
		cin>>x>>y;
		BFS(x,y);
		cout<<ans*t<<endl;
	}
	return 0; 
}

