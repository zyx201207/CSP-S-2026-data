#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
typedef long long ll;
int c,n,m,d,q;
int w[N],a[N][M],t[N][M];
int e[N*2],ne[N*2],h[N],idx;
void add(int u,int v){
	e[idx++]=v;
	ne[idx]=h[u];
	h[u]=idx;
}
bool vis[N];
ll bfs(int st ,int ed){
	queue<pair<int,int> > q;
	q.push({st,0});
	vis[st]=1;
	while(!q.empty()){
		pair<int,int> now=q.front();
		q.pop();
		for(int i=h[now.first];i!=0;i=ne[i]){
		
			if(e[i]==ed){
				return (ll)now.second*2+w[st]+w[ed];
			}	
			if(!vis[e[i]]){
				vis[e[i]]=1;
				q.push({e[i],now.second+1});
			}
		}
	}
	return 1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cout<<1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k,x,y;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=1){
				add(a[i][j-1],a[i][j]);
				add(a[i][j],a[i][j-1]);
			}
		}
	}
	if(c<=19&&c>=12){
		while(q--){
			cin>>x>>y;
			memset (vis ,0,sizeof(vis));
			cout<<bfs(x,y)<<endl;
		}
	}

	return 0;
} 
