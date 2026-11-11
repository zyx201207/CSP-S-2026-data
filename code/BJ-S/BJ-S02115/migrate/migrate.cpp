#include<bits/stdc++.h>
using namespace std;
unsigned long long c,d,t,ans,s[2000100],sum[2000100],a[2000100];
int n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		unsigned long long k=a[1],cnt=0;
		for(int i=2;i<=n;i++){
			sum[i]=a[i]-k;
			k=a[i];
		}
		for(int i=3;i<=n;i++)
			cnt=cnt+(sum[i]-sum[i-1]);
		if(cnt==0){
			if(sum[2]*2<=d) ans=n-3;
		}
		else{
			for(int i=2;i<=n;i++){
				if(sum[i]+sum[i+1]<=d&&sum[i+2]<=d&&sum[i+2]+sum[i+1]<=d) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
