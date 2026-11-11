#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,p=0,sum[100];
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		int a[10000];
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		for(int j=1;j<n-1;j++){
			if(a[j]-a[j-1]!=a[j+1]-a[j]){
				n=j+1;
				break;
			}
		}
		for(int k=0;k<n;k++){
			for(int z=d-1;z<n;z++){
				if(z-k>d){
					if(d<=2){
						if((z-k)/d==1&&(z-k)%d!=0){
							sum[i]++;	
						}
					}
					if(d>2){
						if((z-k)/d==1&&(z-k)%d!=0&&(z-k)%2!=0){
							sum[i]++;	
						}
					}
					
				}
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<sum[i]<<endl;
	}
	return 0;
}
