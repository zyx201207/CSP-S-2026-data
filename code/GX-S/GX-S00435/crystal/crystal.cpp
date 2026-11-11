#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
ll a[N],m,b[N];
int n,top=0;
map<ll ,ll > p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		p[a[i]]++;
		if(p[a[i]]==1) b[++top] = a[i];
	}
	ll ans = -999;
	sort(b+1,b+top+1);
	for(int i=1; i<=top; i++){
		ll num = p[b[i]];
		ll mm = m;
		for(int j=i-1; j>=1; j--){
		ll cnt = p[b[j]];
		ll delta = abs(b[i] - b[j]);
		if(delta * cnt <= mm){
			num += cnt;
			mm -= delta*cnt;
		}else{
			ll rea = mm / delta;
			num += rea;
			break;
			}
		}
			ans = max(num,ans);
		}
		cout << ans;
		return 0;
}	
