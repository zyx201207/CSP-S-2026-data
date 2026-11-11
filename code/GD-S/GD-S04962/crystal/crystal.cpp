#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e+5;
ll n,m;
ll a[N];
ll b[N];

bool cmp(ll x,ll y){
	return x<y;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		ll num=0;
		ll k=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=k){
				num++;
				k-=a[i]-a[j];
			}
		}
		ans=max(num,ans);
	}
	cout<<ans+1;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
 
