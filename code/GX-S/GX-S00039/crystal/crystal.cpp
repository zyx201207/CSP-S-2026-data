#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[500005],ans,k,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll l=0,p=1;
	for(ll i=1;i<n;i++){
		k+=(a[i]-a[i-1])*(i-l);
		while(l<i && k>m){
			k-=a[i]-a[l];
			l++;
			p--;
		}
		p++;
		ans=max(ans,p);
	}
	cout<<ans;
	return 0;
}
