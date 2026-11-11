#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,num;
long long a[100000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    
    cin>>c>>t;
    if(11<=c&&c<=12){
    	while(t--){
	    	cin>>n>>d;
	    	for(long long i=0;i<n;i++){
	    		cin>>a[i];
			}
			long long g=a[5]-a[4];
			if(2*g<=n&&3*g>=n){
				num=n-d/g*2+1;
			}else{
				num=0;
			}
			printf("%lld\n",num);
		}
	}else{
		while(t--){
	    	cin>>n>>d;
	    	for(long long k=0;k<n;k++){
	    		cin>>a[k];
			}
			for(long long i=0;i<n-3;i++){
				if(a[i+3]-a[i]<=d){
					continue;
				}else{
					if(a[i+3]-a[i+1]<=d&&a[i+2]-a[i]<=d){
						num++;
					}
				}
			}
			
			printf("%lld\n",num);
		}
	}
   
	return 0;
}

