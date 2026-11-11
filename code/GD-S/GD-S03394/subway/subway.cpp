#include<bits/stdc++.h>
using namespace std;
const int MAXM=5e4+5;
int n,m,d,w[MAXM],k[505],T[505][505],l[505][MAXM],t[505][MAXM];
bool flag[505][MAXM];
void solve(int x,int y){
	int time=w[x]+w[y],r=-1,lx=0,ly=0;
	int lX_1[505]={0},lY_1[505]={0};
	for(int i=1;i<=n;i++){
		if(flag[i][x]) lX_1[++lx]=i;
		if(flag[i][y]) lY_1[++ly]=i;
	}
	for(int i=1;i<=lx;i++){
		for(int j=1;j<=ly;j++){
			if(r<=0)r=T[lX_1[i]][lY_1[j]];
			r=min(T[lX_1[i]][lY_1[j]],r);
		}
	}
	printf("%d\n",time+r);
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int u;
			scanf("%d",&u);
			l[i][j]=u;
			scanf("%d",&t[i][u]);
			flag[i][u]=true;
		}
	}
	int u=1<<25;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			T[i][j]=u;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int le=1;le<=k[i];le++){
				int op=l[i][le];
				if(flag[i][op]&&flag[j][op]){
					T[i][j]=min(T[i][j],t[i][op]+t[j][op]);
					T[j][i]=T[i][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int oi=1;oi<=n;oi++){
				T[i][j]=min(T[i][oi]+T[oi][j],T[i][j]);
				T[j][i]=T[i][j];
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		solve(x,y);
	}
	return 0;
}
