#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000006];
long long ans=0;
long long cts[2000006],ctn=0;
void solve(){
	ctn=0;
	ans=0;
	for(int i=1; i<=n-3; i++){
		if(max(llabs(a[i+2]-a[i]),llabs(a[i+3]-a[i+1]))<=d&&d<llabs(a[i+3]-a[i])){
			cts[++ctn]=i;
		}
	}
	ans+=ctn;
	for(int i=1; i<ctn; i++){
		ans+=1ll*2*(cts[i+1]-cts[i]-1);
	}
	if(ctn>0&&cts[ctn]<n-3)ans+=n-3-cts[ctn];
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	cin>>c>>t;
	for(int i=1; i<=t; i++){
		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>a[i];
		solve();
	}
	return 0;
}

