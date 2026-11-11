#include <bits/stdc++.h>
using namespace std; 
int w[500010],k[510];
int a[510][50010];
int t[510][50010];
int c,n,m,d,q; 
long long ans=0,sum=0,xia=0;
int sx=0,sy=0,ex=0,ey=0,dx=0,dy=0;
int stat,ed,in;
void dfs(int nx,int ny){
	bool q=0; 
	if(nx==ex && ny==ey){
		for(int i=dx+1;i<ex;i++) sum-=t[ny][i],q=1;
		cout<<sum<<endl;
		return ;
	} 
	if(ny!=ey){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==in && a[i][j]==ed){
					q=1;
					sum+=t[i][j];
					in=a[i][j];
					return ;
					break;
				}
				else if(a[i][j]==in && i!=ny){
					q=1;
					dx=j,dy=i;
					sum+=t[i][j]+t[i][j+1];
					in=a[i][j+1];
					dfs(j+1,i);
					break;
				}
			}
		}
	}
	if(!q){
		sum+=t[ny][nx+1];
		in=a[ny][nx+1];
		dfs(nx+1,ny);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		sum=0,ex=0,ey=0,sx=0,sy=0;
		bool u=0;
		cin>>stat>>ed;
		in=stat;
		sum+=w[stat]+w[ed];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(sx!=0 && sy!=0 && ex!=0 && ey!=0){
					u==1;
					break;
				}
				if(a[i][j]==stat){
					sx=j,sy=i;
				}
				if(a[i][j]==ed){
					ex=j,ey=i;
				}
			}
			if(u) break;
		}
		sum+=t[sy][sx];
		dfs(sx,sy);
	} 
	return 0;
}
