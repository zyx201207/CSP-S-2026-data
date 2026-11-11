#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll a[N],n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll ans=1,sum=0;
	for(ll i=2,j=0;i<=n;i++){
		if(i>1) sum+=(a[i]-a[i-1])*(i-1-j);
		while(sum>m&&j<n){
			j++;
			sum-=(a[i]-a[j]);
		}
		ans=max(ans,i-j);
	}
	cout<<ans<<"\n";
	return 0;
}
//5 5
//1 2 4 8 9

