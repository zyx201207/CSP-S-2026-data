#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					sum+=1;
				}
			}
		}
		cout<<sum;
		sum=0;
	}
	return 0;
}
