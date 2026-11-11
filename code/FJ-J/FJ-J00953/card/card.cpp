#include<bits/stdc++.h>
using namespace std;
int pai[1000010],dian[500010],chu[500010],p[100010]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,wei,nn,shu,zhi,qian;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			pai[i]=p[i];
		}
		nn=n;
		wei=i;
		shu=n-i+1;
		qian=i;
		while(shu>0){
			dian[pai[wei]]+=1;
			
			shu-=1;
			if(dian[pai[wei]]==2){
				dian[pai[wei]]==1;
				pai[wei]=0;
				for(int j=i;j<wei;j++){
					if(pai[wei]==pai[j]){
						qian=j+1;
						break;
					}
				}
				
				
				
				
			}
			
			wei+=1;
			
		}
		for(int j=qian;j<=wei-1;j++){
			chu[pai[j]]+=1;
		}
		for(int j=1;j<=m;j++){
			dian[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<chu[i]<<' ';
	}
	
	
	
	
	
	return 0;
} 
