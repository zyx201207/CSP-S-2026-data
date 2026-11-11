#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll ans=0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<ll> a(n+3,0);
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	ll p=1;
	ll d=a[2]-a[1];//cout<<"d:"<<d<<endl;
	for(ll i=3;i<=n;++i){
		if(a[i]-a[i-1]==d)p++;
//		cout<<p<<endl;
	}
	if(p==n-1)//A and B
	{
		for(ll i=1;i<=n;++i){
			ll a=n-i;
			if(a*d*(a+1)<=2*m){
				ans=a;
				cout<<ans+1<<endl;
				exit(0);
			}
		}
	}
	else
	{
		sort(a.begin()+1,a.begin()+1+n);
		
	//	for(ll i=1;i<=n;++i)cout<<a[i]<<" ";cout<<endl;
		
		ll sum=0;
		for(ll i=1;i<=n;++i){
			sum=0;
	//		cout<<"i:"<<i<<endl;
			ll ans1=0;
			for(ll j=i-1;j>=1;--j){
	//			cout<<"\tj  :"<<j<<endl;
	//			cout<<"\t"<<sum+(a[i]-a[j])<<endl;
				if(sum+(a[i]-a[j]) <= m){
					ans1++;
					sum+=a[i]-a[j];
				}else{
					break;
				}
	//			cout<<"\tsum:"<<sum<<endl;
			}
			ans=max(ans,ans1);
		}
		cout<<ans+1<<endl;
	}
	return 0;
}

