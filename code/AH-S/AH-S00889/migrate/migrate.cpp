#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[1000005];
long long sum[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int tt=1;tt<=t;tt++){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			sum[i]=x[i]-d;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(sum[i]+sum[j]==0){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
