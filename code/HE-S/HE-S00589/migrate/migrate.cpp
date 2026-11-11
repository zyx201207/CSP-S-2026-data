#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k,ans=0;
ll a[2000100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(k==1){
			cout<<'0'<<'\n';
			continue;
		}
		ll pa=k*2;
		for(int i=1;i<=n-3;i++){
			bool ab=0,bb=0,cb=0;
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]+k-1)ab=1;
				if(a[j]==a[i]+k)bb=1;
				if(a[j]==a[i]+k+k-1)cb=1;
				if(ab&&bb&&cb)break;
			}
			if(ab&&bb&&cb)ans++;
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
