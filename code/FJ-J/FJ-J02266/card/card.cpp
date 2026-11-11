#include <bits/stdc++.h>
using namespace std;
//int n,m,su[51],d[31]={0,0};//int n,m,su[500001],d[300001]={0,0};
int n,m,su[6];
//void a(int q){
//	int bi[m+1],z[n+1],zs=1;
//	for(int i=q;q<=n;q++){
//		if(bi[su[i]]==0){
//			bi[su[i]]==1;
//			z[zs]=su[i];
//			zs++;
//		}else{
//			bi[su[i]]=0;
//			while(z[zs-1]!=su[i]){
//				z[zs-1]=0;
//				zs--;
//			}
//			z[zs-1]=0;
//			zs--;
//		}
//	}
//	while(zs!=1){
//		d[z[zs-1]]++;
//		zs--;
//	}
//}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>su[i];
	}
//	for(int i=1;i<=n;i++){
//		a(i);
//	}
//	for(int i=1;i<=n;i++){
//		cout<<d[i]<<" ";
//	}
	if(n<=5&&m<=2){
		int d[3]={0};
		int z[6]={0},zs=1,bi[3]={0,0,0};
		for(int i=1;i<=n;i++){
			zs=1; 
			for(int j=i;j<=n;j++){
				if(bi[su[j]]==0){
					bi[su[j]]=1;
					z[zs]=su[j];
					zs++;
				}else{
					bi[su[j]]=0;
					while(z[zs-1]!=su[j]){
						z[zs-1]=0;
						zs--;
					}
					z[zs-1]=0;
					zs--;
				}
//				cout<<z[1]<<" "<<z[2]<<" "<<z[3]<<" "<<z[4]<<" "<<z[5]<<endl;
			}
			while(zs!=0){
				d[z[zs-1]]++;
				z[zs-1]=0;
				zs--;
			}
			
		}
		cout<<d[1]<<" "<<d[2]<<endl;
		return 0;
	}
	return 0;
}
