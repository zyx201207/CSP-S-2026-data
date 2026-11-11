#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k,a[510][500010],t[510][500010],x,y,nx1,ny1;
long long ans,as,mx;
bool b[510][500010];
long long bfs(int nx,int ny,long long a){
	if(nx==nx&&ny==ny) return ans;
	a+=t[nx1][ny1];
	if(b[nx+1][ny]&&nx!=n) return bfs(nx+1,ny,a);
	if(b[nx-1][ny]) return bfs(nx-1,ny,a);
	for(int i=1;i<=500000-ny;i++){
		if(b[nx][ny+i]&&(b[nx+1][ny+i]||b[nx-1][ny+i])) return bfs(nx,ny+i,a);
	}
	for(int i=1;i<ny;i++){
		if(b[nx][ny-i]&&(b[nx+1][ny-i]||b[nx-1][ny-i])) return bfs(nx,ny-i,a);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			b[i][a[i][j]]=true;
		}
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=500000;j++){
				if(b[i][j]==x){
					nx1=i;
					ny1=j;
					as=bfs(i,j,0);
					mx=max(mx,as);
				}
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}
