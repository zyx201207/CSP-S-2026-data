#include <bits/stdc++.h>
using namespace std;
const int N=5e5+7;
typedef long long ll;
int n;ll m;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	 freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	int ans=1, pos=1;ll rst=m;
	for(int i=2;i<=n;i++){
		ll dt=a[i]-a[i-1];
		while(pos<i && rst<1ll*(i-pos)*dt) rst+=a[i-1]-a[pos++];
		rst-=1ll*(i-pos)*dt;
		ans=max(ans, i-pos+1);
	}
	cout<<ans<<endl;
	return 0;
}