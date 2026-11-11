#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long minn=LONG_LONG_MAX;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1) minn=min(minn,a[i]-a[i-1]);
		}
		if(minn>d){
			cout<<0<<endl;
			continue;
		}
		bool flag=0;
		for(int i=2;i<n;i++){
			if(a[i]-a[i-1]!=a[i+1]-a[i]){
				flag=1;
				break;
			}
		}
		if(flag) cout<<0<<endl;
		int now=1;
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]-a[now]>d){
				ans++;
				now++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
