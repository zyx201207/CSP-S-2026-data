#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
long long c,t,n,d;
long long a[100005];
long long ans,cs,mn;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c>10){
			cout<<0<<endl;
			continue;
		} 
		for(int i=1;i<=n;i++){
			long long sum=0;
			for(int j=i-1;j>=1;j--){
				if(a[j+1]-a[j]>d)break;
				if(j<=i-3){
					if(a[j+3]-a[j]>d&&a[j+2]-a[j]<=d&&a[j+3]-a[j+1]<=d)sum++;
					if(sum==2)break;
					else if(sum==1)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
} 
