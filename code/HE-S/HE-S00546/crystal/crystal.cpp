#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll lim=1e12;
ll n,m;
ll tot,ret;
ll s[500007],a[500007],cnt;

bool check(ll x,ll p){
	return (p-x+1ll)*a[p]-s[p]+s[x-1]<=m;
}

ll bs(ll p){//return a pos that (p-pos+1)-sp+s[pos-1]<=m
	ll l=1,r=p,mid,ans=-1;
	while(l<=r){
		mid=l+((r-l)>>1);
		if(check(mid,p)){
			r=mid-1;ans=mid;
		}
		else {
			l=mid+1;
		}
	}
	return ans;
}

int main()
{
//	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i]=a[i]+lim;
	}
	sort(a+1,a+1+n);
	ll lst=lim+7;//////////
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];//////////
	}
//	for(int i=1;i<=n;i++)cout<<s[i]<<" ";
	for(int i=1;i<=n;i++){
		ll lb=bs(i);
		ret=max(i-lb+1,ret);
//		cout<<i<<" "<<lb<<" "<<ret<<"\n";
	}
	cout<<ret;
	//5 5 1 2 4 8 9
	return 0;
}


