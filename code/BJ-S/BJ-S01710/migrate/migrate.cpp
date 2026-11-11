#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				long long num=(a[j]-a[i])%d;
				long long cnt=0;
				bool flag=0;
				for(int k=i;k<=j;k++){
					if(a[k]>=a[i]+num&&a[k]<=a[j]-num) cnt++;
					if(k+1<=j&&a[k+1]-a[k]>d){flag=1;break;}
				}
				if(flag) continue;
				if(cnt==0) cnt=j-i+1;
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
