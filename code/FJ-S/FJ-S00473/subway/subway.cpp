#include<bits/stdc++.h>
using namespace std;
long long N=1e5+1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int m,w[N],min=N,n,c,d,q,k[N],a[N][N],t[N][N],z[N][N]={0},zs[N][N]={0},zd[N][N]={0};
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;i<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			for(int x=0;x<k[i];x++){
				if(a[i][x]==j){
					z[j-1][i]=t[i][x];
					zd[j-1][i]=1;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			for(int x=0;x<n;x++){
				if(zd[i][x]==zd[j][x]&&zd[i][x]==1){
					zs[i][j]=zs[j][i]=z[j][x]+z[i][x];
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			bool flag=true;
			for(int x=0;x<n;x++){
				if(zd[i][x]==zd[j][x]&&zd[i][x]==1){
					flag=false;
					break;
				}
			}
			min=N;
			if(flag){
				for(int x=0;x<m;x++){
					if(x==i||x==j){
						continue;
					}
					for(int a=0;a<n;a++){
						for(int b=0;b<n;b++){
							if(zd[i][a]==zd[x][a]&&zd[i][a]==1&&zd[j][b]==zd[x][b]&&zd[j][b]==1){
								zs[i][j]=zs[j][i]=z[x][a]+z[x][b]+z[i][a]+z[j][a];
								if(zs[i][j]<min){
									min=zs[i][j];
								}else{
									zs[i][j]=min;
								}
							}
						} 
					}
				}
			}else{
				continue;
			}
		}
	}
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		cout<<zs[a][b]+w[a]+w[b]<<endl;
	}
	return 0;
} 
