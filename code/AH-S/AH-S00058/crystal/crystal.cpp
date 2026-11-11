#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],maxn=1,sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,sum=0;
	for(ll r=2;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m&&l<r){
			sum-=a[r]-a[l];
			l++;
		}
		if(sum<=m) maxn=max(maxn,r-l+1);
	}
	cout<<maxn;
	return 0;
}
