#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pb push_back
#define fir first
#define sec second
const int N=5e5+7;
// LONG LONG!!!
ll n,m,a[N],flag=1,ans=1,sum[N],Sum[N],d[N];
bool check(ll x){
	ll res=0;
	for(ll i=x;i<=n;i++){
		res+=(Sum[i]-Sum[i-x])-(sum[i]-sum[i-x])*(i-x);
		if(res<=m){
			return 1;
		}
		res=0;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+d[i];
	}
	for(ll i=1;i<=n;i++){
		Sum[i]=Sum[i-1]+(i-1)*d[i];
	}
	ll l=2,r=n;
	while(l<r){
		ll mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
// O(nlogn)
