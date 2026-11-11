#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
ll sum[500005];
ll sum1[500005];
ll n,m;
ll maxx=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	for(int i=1; i<=n; i++) {
		if(a[i]!=i) {
			f=1;
		}
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		sum[i]=abs(a[i]-a[i-1]);
	}
	bool ff=0;
	for(int i=3; i<=n; i++) {
		if(sum[i]!=sum[i-1]) {
			ff=1;
		}
	}
	if(f==0) {
		ll ssm=0;
		for(int i=1; i<=n; i++) {
			ll mm=i*a[i];
			ssm+=a[i];
			if(mm-ssm<=m) {
				maxx=i;
			}
		}
	} else if(ff==0) {
		ll ssm=0;
		for(int i=1; i<=n; i++) {
			ll mm=i*a[i];
			ssm+=a[i];
			if(mm-ssm<=m) {
				maxx=i;
			}
		}
	} else{
		sort(a+1,a+n+1);
		ll ssm=0;
		for(int i=1; i<=n; i++) {
			ll mm=i*a[i];
			ssm+=a[i];
			if(mm-ssm<=m) {
				maxx=i;
			}else{
				break;
			}
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
