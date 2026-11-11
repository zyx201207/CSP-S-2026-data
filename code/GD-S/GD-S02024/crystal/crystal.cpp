#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int kmaxN =  5e5 + 10;
ll n,m,a[kmaxN];
ll ans = 1,sum,tot;
bool ff = 1;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(i > 2 && a[i] - a[i-1] != a[2] - a[1]) ff = 0;
	}
	if(ff){
		int midp = (n + 1) / 2;
		tot = m;
		for(int i = midp-1;i >= 1;i--){
			if(tot >= 2ll * (a[midp] - a[i])){
				tot -= 2ll * (a[midp] - a[i]);
				ans += 2;
			}else if(tot >= 1ll * (a[midp] - a[i])){
				ans++;
				tot -= 1ll * (a[midp] - a[i]);
			}
		}
		if(n % 2 == 0 && tot >= (a[n] - a[midp])) ans++;
		cout<<ans;
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		sum = 1,tot = m;
		for(int j = i - 1;j >= 1;j--){
			if(a[i] - a[j] <= tot){
				sum++;
				tot-=a[i]-a[j];
			}else break;
		}
		ans = max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
