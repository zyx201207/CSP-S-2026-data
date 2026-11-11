#include<bits/stdc++.h>
using namespace std;
int a[2000003];
int main(){
	freopen("migrate.out","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++) scanf("%d",&a[j]);
		int ans=0;
		for(int j=1;j<=n;j++){
			int need=d+d-1;
			for(int t=j;t<=n;t++){
				if(a[t]-a[t-1]>d) break;
				if(a[t]-a[j]==need){
					ans++;
					//cout<<a[t]<<" "<<a[j]<<endl;
				}
				if(a[t]-a[j]>need) break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
