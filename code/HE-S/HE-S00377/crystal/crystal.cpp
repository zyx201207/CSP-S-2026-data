#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],lans=1,rans=1,lto[500005],rto[500005],same=0,ltoo[500005],rtoo[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		lto[i-1]=a[i]-a[1];
		ltoo[i-1]=a[i]-a[i-1];
	}
	for(ll i=n;i>=1;i--){
		rto[i]=a[n]-a[i-1];
		rtoo[i]=a[i]-a[i-1];
	}
	if(m>=10000000){
		ll ans=1;
		ll sum=a[2]-a[1];
		for(ll i=1;i<=n;i++)
		{
			m-=sum*i;
			if(m<=0) break;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	ll t=m;
	for(ll i=1;i<=n;i++){
		m-=lto[i];
		if(ltoo[i]!=0&&m<=0) break;
		lans++;
	}
	for(ll i=n;i>=1;i--){
		t-=rto[i];
		if(rtoo[i]!=0&&t<=0) break;
		rans++;
	}
	cout<<max(lans,rans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
