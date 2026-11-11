//GZ-S00147 杨俊毅 遵义市南白初级中学 
#include<bits/stdc++.h>
using namespace std;
int t,c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		bool q=1;
		long long n,d,ans=0;
		cin>>n>>d;
		vector<long long> x(n+1,0);
		vector<long long> dis(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long k=x[2]-x[1];
		for(int i=2;i<=n;i++){
			if(x[i]-x[i-1]!=k){
				q=0;
				break;
			}
		}
		if(q){
			if(d<2*k){
				ans=0;	
			}else{
				ans=n/2+1;
			}
			cout<<ans<<" ";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;i<=n;j++){
			if(i!=j&&j-i>=1){
				if(dis[j]-dis[j-1]<=d){
					if(j-i>1){
						if(dis[j]-dis[j-2]<=d)
						break;
					}
					ans++;
				}
			}
			}
		}
		cout<<ans<<" ";
	}
	return 0;
}
