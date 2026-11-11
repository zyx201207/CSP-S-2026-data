//@贵阳市第三中学 李盱盈 GZ-S00109
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
ll n,M;
vector<ll>a,p,b;
bool check(ll m){
	if(m>n)return 0;
	ll sum=0;
	for(ll i=m;i<=n;i++){
		sum=p[i]-p[i-m];
		double x=sum*1.0/(m*1.0);
		ll it=i,y=a[i];
		ll cnt=0;
		cnt+=m*y-sum;
		if(cnt<=M)return 1;
	}
	return 0;
}
void zs(){
	cin>>n>>M;
	a.assign(n+1,0),p.assign(n+1,0),b.assign(n+2,0);
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	for(ll i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	for(ll i=n;i>=1;i--)b[i]=b[i+1]+a[i];
	ll l=0,r=1e6;
	while(l+1!=r){
		ll mid=(l+r)/2;
		if(check(mid))l=mid;
		else {r=mid;
		}
	}
	cout<<l<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll t=1;
	//cin>>t;
	while(t--)zs();
	return 0;
}
//Oct31==Dec25?
