#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans;
bool ck(ll x){
	ll s=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x)break;
		s+=(x-a[i]);
	}
	return s<=m;
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
	ll nw=0,l=1;
	for(int i=2;i<=n;i++){
		nw+=(a[i]-a[i-1])*(i-l);
		if(nw>m){
			while(l<i&&nw>m){
				nw-=a[i]-a[l++];
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
