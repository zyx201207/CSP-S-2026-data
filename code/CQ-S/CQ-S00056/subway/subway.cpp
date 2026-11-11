#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c,n,m,d,p,k1;
struct N{
	int sta,t_s;
};

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	int time[m+5][m+5];
	memset(time,0x3f3f3f3f,sizeof(time));
	int t_m[m+5];
	for(int i=1;i<=m;i++){
		scanf("%d",&t_m[i]);
		time[i][i]=0;
	}
	N f[505][m+5]; 
	int mid=0,is=1;
	for(int i=1;i<=n;i++){
		cin>>k1;
		for(int j=1;j<=k1;j++){
			scanf("%d%d",&f[i][j].sta,&f[i][j].t_s);
			if(mid==0)mid=f[i][j].t_s;
			else if(mid!=f[i][j].t_s)is=0;
		}
		for(int j=1;j<=k1;j++){
			for(int j1=j+1;j1<=k1;j1++){
				int a1=f[i][j].sta,b1=f[i][j1].sta;
				time[a1][b1]=min(time[a1][b1],f[i][j].t_s+f[i][j1].t_s);
				time[b1][a1]=min(time[b1][a1],f[i][j].t_s+f[i][j1].t_s);			
			}			
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			for(int k=1;k<=m;k++){
				if(k==i||k==j)continue;
				if(time[i][j]+time[j][k]<time[i][k]){
					time[i][k]=time[i][j]+time[j][k];
					time[k][i]=time[i][j]+time[j][k];
				}
			}
		}
	}
	while(p--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",t_m[x]+t_m[y]+time[x][y]);
	}
	return 0;
} 
