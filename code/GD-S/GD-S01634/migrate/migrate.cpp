#include<iostream>
#include<algorithm>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long gm,t;
	cin>>gm>>t;
	while(t--){
		long long n,d,ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
			cin>>a[i];
		long long ks=2;
		for(long long k=3;k<=n;k++){
			if(a[k]-a[k-1]<=d&&k!=n)
				continue;
			long long j=ks-2;
			if(k!=n)
				k--;
			for(long long i=ks;i<=k-2;i++){
				if(a[i+2]-a[i]<=d&&a[i+1]-a[i-1]<=d&&a[i+2]-a[i-1]>d){
					ans+=(i-j-1)*(k-i-1);
					j=i-1;
				}
			}
			k++;
			ks=k;
		}	
		cout<<ans<<'\n';
	}
}
