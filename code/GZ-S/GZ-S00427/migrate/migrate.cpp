//GZ-S00427 卢泓宇 遵义市第一中学
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    for(int q=1;q<=t;q++){
    	cin>>n>>d;
    	int x[n+1],num=0,sum=0,g=0;
    	for(int i=1;i<=n;i++){
    	   	cin>>x[i];
		}
		for(int i=1;i<=n;i++){
    	   	for(int j=n;j>i;j--){
    	   	if(x[j]-x[i]<=d){
    	   		num++;
    	   		if(j==n){
    	   			break;
				}
			}
		}
		if(num==0){
		   if(g==1){
		   	sum--;
		   }	
		}
		g=0;
		if(num==2){
			sum++;
			g=1;
		}
		num=0;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

