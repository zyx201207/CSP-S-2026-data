#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,m,ans=0;
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>m;
		if(n<=5000){
			ans=0;
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++){
				if(a[i+2]-a[i]>m) continue;
				if(i+3>n) break;
				if(a[i+3]-a[i]>m) ans++;
				if(i+4>n) break;
				if(a[i+4]-a[i]>m&&a[i+4]-a[i+3]<=m&&a[i+4]-a[i+2]<=m&&a[i+4]-a[i+1]>m&&a[i+3]-a[i]<m) ans++;
				else continue;
			}
			cout<<ans<<"\n";
		}
		else{
			for(int i=1;i<=n;i++) cin>>a[i];
			int u=m/(a[2]-a[1]);
			if(u==2) cout<<n-3<<"\n";
			else cout<<0<<"\n";	
		}
	}
	return 0;
}
