#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],num[N];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll l=1,r=1,nw=0;
	while(r<=n){
		nw+=(r-l)*(a[r]-a[r-1]);
		while(nw>m&&l<=r) nw-=a[r]-a[l],l++;
		num[r]=r-l+1;
		r++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,num[i]);
	cout<<ans<<endl;
	return 0;
}
