#include<bits/stdc++.h>
using namespace std;
const long long M=2e6+1,M1=1e18;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,T;
	cin>>c>>T;
	while(T--){
		long long n,d;
		cin>>n>>d;
		long long a[M]={};
		bool b[M]={};
		long long ans=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3){
				if(a[i]-a[i-2]>d&&a[i]-a[i-1]<=d&&a[i-1]-a[i-2]<=d){
					b[i-1]=1;
				}
			}
		}
		if(a[3]-a[1]>d){
			b[1]=1;
		}
		if(a[n]-a[n-2]>d){
			b[n]=1;
		}
		for(long long i=1;i<=n;i++){
			if(i>=4){
				if(a[i-1]-a[i-3]<=d&&a[i]-a[i-2]<=d&&a[i]-a[i-3]>d){
					long long left=1,right=1;
					for(int j=i-4;j>=1;j--){
						if(b[j]==1){
							left++; 
						} else{
							break;
						}
					}
					for(int j=i+1;j<=n;j++){
						if(b[j]==1){
							right++; 
						} else{
							break;
						}
					}
					ans+=left*right;
				}
				
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}

