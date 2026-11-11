#include<bits/stdc++.h>
using namespace std;
long long n,m,x=1e9,y=0,z=0,ans=0;
int main(){	
	freopen("crystal4","r",stdin);
	freopen("crystal4","w",stdout);
	cin>>n>>m;
	long long a[n+5];
	if(n<=5000){
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++){
			y=0;
			for(long long j=1;j<=n;j++){
				if(a[i]-a[j]>=0){
					y+=a[i]-a[j];
				}
				else y+=a[j]-a[i];
			}
			if(y<=x){
				z=a[i];
				x=y;	
			}
		}
		for(long long i=1;i<=n;i++){
			if(a[i]<=z&&m>=z-a[i]){
				m-=z-a[i];
				ans++;
			}
			else continue;
		}
		cout<<ans;
	}
	else{
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==i) y++;
		}
		if(y==n){
			long long h=n/2;
			for(long long i=h-1;i>=1;i--){
				if(m>=h-i){
					ans++;
					m-=h-i;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
