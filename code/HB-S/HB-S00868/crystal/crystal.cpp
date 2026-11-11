#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=1e5*5+10;
ll n,m,a[MAXN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll l=1,r=1,sum=0,ans=0;
	while(l<=r){
		if(a[r]*(r-l)-sum<=m){
			sum+=a[r];
			ans=max(ans,r-l+1);
			r++;
		}else{
			sum-=a[l];
			l++;
		}
		if(r>n) break;
	}
	cout<<ans<<'\n';
	return 0;
}
