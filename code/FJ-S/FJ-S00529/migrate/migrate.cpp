#include<bits/stdc++.h>
using namespace std;
long c,t,n,d,a[2000005],sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(long i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d!=2){
			cout<<0<<endl;
			continue;
		}
		for(long i=1;i<=n;i++){
			for(long j=i;j<=n;j++){
				if(a[j]-a[i]==3){
					for(long k=i;k<=j;k++){
						if(a[j]-a[k]==1||a[j]-a[k]==2){
							sum++;
							break;
						}
					}
				}
				else{
					for(long k=i;k<=j;k++){
						if(a[j]-a[k]==a[j]-a[k]){
							sum++;
							break;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	} 
	return 0;
}
 
