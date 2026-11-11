//王晨懿 GZ-S00422 贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		int a[n+1],x[n+1];
		for(int j=1;j<=n;j++){
			cin>>x[j];
			if(j>=2)a[j]=x[j]-x[j-1];
		}
		int sum1=0,sum2=0;
		for(int j=1;j<=n-2;j++){	
			for(int k=j+2;k<=n;k++){
				bool flag=1;
				for(int r=j+1;r<=k;r++){
					if(a[r]>d){
						flag=0;
						break;
					}
					sum1+=a[r];
				}
				if(flag==0){
					flag=1;	continue;
				}
				if(sum1%d==0){
					flag=1; continue;
				}
				if((sum1/d)+1==sum1/(d+1)){
					flag=1; continue;
				}
				sum2++;
			}	
		}
		cout<<sum2-1;
	}
	return 0;
}
