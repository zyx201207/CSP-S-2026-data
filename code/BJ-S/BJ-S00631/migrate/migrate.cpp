#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(x[i]+d>=x[j]){
					continue;
				}
				long long z=x[j]-x[i];
				if(z%d!=0){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
