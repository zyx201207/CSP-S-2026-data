/*ÎÒÊÇ513*/
#include <bits/stdc++.h>
using namespace std;
int k[503];
int statime[503][20007];
int iotime[20007];
bool subline[20007][507];
int tt[20007][20007];
//bool wemt[20007]
int c,n,m,d,q;//who is dq
int bfs(int tm, int start, int end){
	if(tt[start][end]!=0){
		return tt[start][end];
	}
	for(int i=0;i<m;i++){
		if(subline[start][m]&&subline[end][m]){
			return tt[start][end]=tt[start][end]<iotime[start]+iotime[end]?tt[start][end]:iotime[start]+iotime[end];
		}	
	}
	tm+=iotime[start];
	for(int i=0;i<m;i++){
		if(subline[start][i]){
			for(int j=0;j<n;j++){
				if(subline[j][i]){
					int b=bfs(tm+statime[i][j],j,end);
					tt[start][end]=tt[start][end]<b?tt[start][end]:b;
				}
				
			}
		}
		
	}
	return tt[start][end];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++){
		scanf("%d",iotime+i);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++){
			int aij;
			scanf("%d",&aij);
			scanf("%d",&statime[i][aij]);
			subline[aij][i]=true;
		}
	}
	for(int i=0;i<q;i++){
		//memset(went,0);
		int xr,yr;
		scanf("%d%d",&xr,&yr);
		bfs(0,xr,yr);
	}
} 
