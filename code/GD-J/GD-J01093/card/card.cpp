#include<bits/stdc++.h>
using namespace std;

struct scard{
	int ds;
	//int z=0;
};
scard a[520000];
int n,m,z[320000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		a[i].ds=c;
	}
	int k=0;
	while(k<=n){
		scard b[520000];
		int pd[320000]={};
		int bj=0;
		k++;
		for(int i=k;i<=n;i++){
			bj++;
			b[bj].ds=a[i].ds;
			if(pd[b[bj].ds]==0){
				//bj++;
				pd[b[bj].ds]=1;
				//cout<<"111  11  ";
			}
			else{
				//pd[b[bj].ds]=0;
				int s=bj;
				while(1){
					bj--;
					pd[b[bj].ds]=0;
					if(b[bj].ds==b[s].ds){
						//pd[b[j].ds]=1;
						break;
					}
					
				}
			}
			
		}
		for(int i=1;i<=bj;i++){
			z[b[i].ds]++;
			//cout<<b[i].ds<<" ";
		}
		//cout<<endl;
		//k++;
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<" ";
	}
	return 0;
} 
