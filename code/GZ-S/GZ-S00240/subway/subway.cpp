//GZ-S00240 ¹óÑôË«Áú»ª÷ëÑ§Ğ£ ÎâÅæÁØ 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,gs[10005],zx[1005][505],xk[505][3];
long long ans;
bool f[10005];
void bfs(int s,int e){
	ans=0;
	for(int i=1;i<=10005;i++) f[i]=0;
	queue<int> q;
	q.push(s);
	f[s]=0;
	while(!q.empty()){
		int u=q.top();
		f[u]=1;
		q.pop();
		for(int i=1;i<=n;i++){
			if(zx[u][i]){
				ans+=zx[u][i];
				for(int j=1;j<=n;j++){
					if(f[xk[i][j]]) continue;
					q.push({xk[i][j]});
				}
			}
		}
		if(u==e) return;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>gs[i];
	for(int i=1;i<=n;i++){
		int k,v,w;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			zx[v][i]=w;
			xk[i][j]=v;
		}
	}
	int s,e;
	while(q--){
		cin>>s>>e;
		cout<<gs[s]+gs[e]+ans<<endl;
	}
	return 0;
}
