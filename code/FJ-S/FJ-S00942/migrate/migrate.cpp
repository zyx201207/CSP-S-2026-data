#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long c,t;
	cin>>c>>t;
	for(long long l=1;l<=t;l++){
		long long n,d;
		cin>>n>>d;
		long long ans=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]-a[i-1];
		}
		for(long long i=1;i<=n;i++){
			long long r=1,jg=0;
			while(1){
				if(a[i+r]<=a[i]+d)jg++;
				r++;
				if(a[i+r]>a[i]+d)break;
			}
			if(jg==2)ans++;
			jg=0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
