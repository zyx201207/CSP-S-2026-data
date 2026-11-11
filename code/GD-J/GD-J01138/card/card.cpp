#include<bits\stdc++.h>
using namespace std;
long long n,m,ar[500010],zb[500010],zm[500010];
bool qp[500010],yy[500010];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",ar+i);
	}
	for(int i=1;i<=m;i++){
		int pai;
		for(int j=i-1;j<=m;j++){
			if(!yy[j]){
				yy[j]=1;
				pai++;
				zm[pai]=j;
				zb[j]=pai;
			}else{
				for(int z=zb[j];z<=pai;z++){
					qp[zm[z]];
					
				}
			}
		}
		
	}
	return 0;
}
