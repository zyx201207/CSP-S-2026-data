#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long c,t;
long long a[2000005],ct[2000005];
bool b[2000005],b1[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		a[0]=-4e18;
		a[n+1]=4e18;
		long long cnt=0;
		for(int i=2;i<n;i++){
			if(a[i+1]-a[i-1]<=d&&a[i+2]-a[i-1]>d&&a[i+1]-a[i-2]>d){
				b[i]=1;
			}
		}
		long long l=1,k,bl=0,ans=0;
		for(int i=1;i<=n;i++){
			if(i>1&&a[i]-a[i-1]>d){
				l=i,bl=0;
			}
			if(bl==1&&i!=k+2){
				ans++;
			}
			if(b[i]==1&&b[i-1]==1){
				bl++;
				if(bl==2){
					while(l<k){
						l++;
						if(l<=k-2){
							ans++;
						}
					}
					l++;
					bl--;
				}
				k=i-2;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
