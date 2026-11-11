#include<bits/stdc++.h>
using namespace std;
long long n,m,t,luxian[510][510];
int c,ge,ci,gls[200100];
struct qwe{
	long long xz;
	long long gx[21];
	long long dxl[21];
}dian[20010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>ge>>t;
	for(int i=1;i<=m;i++){
		cin>>dian[i].xz;
	}
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=1,y,z;j<=x;j++){
			cin>>y>>z;
			dian[y].gx[gls[y]++]=i;
			dian[y].dxl[gls[y]]=z;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=2;j<=gls[i];j++){
			int x=dian[i].gx[j];
			int y=dian[i].gx[j-1];
			if(!luxian[x][y]){
				luxian[x][y]=dian[i].dxl[j]+dian[i].dxl[j-1];
				luxian[y][x]=luxian[x][y];
				
			}
			else{
				luxian[x][y]=min(luxian[x][y],dian[i].dxl[j]+dian[i].dxl[j-1]);
				luxian[y][x]=luxian[x][y];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(luxian[i][k]&&luxian[k][j]){
					if(!luxian[i][j]){
						luxian[i][j]=luxian[i][k]+luxian[k][j];
						continue;
					}
					luxian[i][j]=min(luxian[i][j],luxian[i][k]+luxian[k][j]);
				}
			}
		}
	}
	while(t--){
		long long  x,y,daan=0;
		cin>>x>>y;
		daan=luxian[dian[x].gx[1]][dian[y].gx[1]];
		for(int i=1;i<=gls[x];i++){
			for(int j=2;j<=gls[y];j++){
				daan=min(luxian[dian[x].gx[i]][dian[y].gx[j]],daan);
			}
		}
		daan+=dian[x].xz+dian[y].xz;
		cout<<daan<<endl;
	}
	return 0;
} 
