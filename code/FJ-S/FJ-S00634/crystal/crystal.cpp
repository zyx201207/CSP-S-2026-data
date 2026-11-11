#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans,o,p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(long long i=1;i<=n;i++){
		b[i]=abs(a[i-1]-a[i]);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			long long ll=0;
			for(long long k=i+1;k<=j;k++){
				for(long long u=k;u<=j;u++){
					ll=ll+b[u];
				}
			}
			if(ll<=m)ans=max(ans,j-i+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
