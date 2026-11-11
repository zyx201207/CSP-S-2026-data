#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=0;
const ll N=5e5+10;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll pos=1,sum=0;
	for(ll i=1;i<=n;i++){
		sum+=a[i];
		while(pos<i&&(i-pos+1)*a[i]-sum>m){
			sum-=a[pos];
			pos++;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans<<"\n";
	return 0;
} /*
-----------------------
5 5
1 2 4 8 9

3
-----------------------
5 8
-3 -1 2 2 7

4
-----------------------
*/
