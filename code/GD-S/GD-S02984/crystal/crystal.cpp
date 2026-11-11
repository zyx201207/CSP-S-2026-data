#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll a[N];
ll x;
bool cmp(ll a,ll b){
	return abs(a-x)<abs(b-x);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans1,ans2;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	x=a[n/2+1];
	sort(a+1,a+n+1,cmp);
	for(ll i=2;i<=n;i++){
		m-=abs(a[i]-x);
		if(m==0){
			ans1=i;
			break;
		}else if(m<0){
			ans1=i-1;
			break;
		}
	}
	sort(a+1,a+n+1);
	x=a[n/2];
	sort(a+1,a+n+1,cmp);
	for(ll i=2;i<=n;i++){
		m-=abs(a[i]-x);
		if(m==0){
			ans2=i;
			break;
		}else if(m<0){
			ans2=i-1;
			break;
		}
	}
	cout<<max(ans1,ans2);
	return 0;
}
