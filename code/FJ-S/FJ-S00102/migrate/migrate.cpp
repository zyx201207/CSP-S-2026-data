#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		cin>>n>>d;
		long long ans=0;
		long long x[2000005]={0};
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		for (int i=1;i<=n;i++){
			
			
			for (int j=i+1;j<=n;j++){
				if (x[j]-x[i]<=d){
					continue;
				}else {
					long long cnt=j-i-2;
					ans+=cnt>=0?cnt:0;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
}
