#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int c,n,m,d,q,s[N],k[N];
int b[N][N],p[N],minn=7e6,t[N][N];
struct Node{
	int x[N];
}a[N];
int vis[N];
void DFS(int idx,int zd,int ys,int jis){
	if(idx == zd || jis == m){
		minn=min(minn,ys);
		return ;
	}
	vis[idx]=1;
	ys+=s[idx];
	for(int i=1;i<=p[idx];i++){
		for(int j=1;j<=k[b[idx][i]];j++){
			if(vis[a[b[idx][i]].x[j]] == 0){
				DFS(a[b[idx][i]].x[j],zd,ys+t[a[b[idx][i]].x[j]][b[idx][i]],jis++);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i].x[j]>>t[a[i].x[j]][i];
			p[a[i].x[j]]++;
			b[a[i].x[j]][p[a[i].x[j]]] = i;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=p[i];j++){
//			cout<<i<<": "<<p[i]<<" "<<b[i][j]<<endl; 
//		}
//	}
	int xx,yy;
	while(q--){
		cin>>xx>>yy;
		memset(vis,0,sizeof vis);
		minn=7e6;
		DFS(xx,yy,0,1);
		cout<<minn<<endl;
	}
	return 0;
}
