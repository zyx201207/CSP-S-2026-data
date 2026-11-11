#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
ll a[N];
ll p[N];
bool cmp(ll a,ll b){
	return a < b;
}

int main(){
	int n,m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll maxn = m + a[n];
	ll tot = -1;
	for(int i = 1;i <= maxn;i++){
		ll ans = 0;
		memset(p,sizeof(p),N);
		for(int j = 1;j <= n;j++){
			if(a[j] > i){
				break;
			}else{
				p[j] = i - a[j];
			}
		}
		sort(p+1,p + n + 1,cmp);
		int k = m;
		int t = 1;
		while(k >= 0){
			
			if(k - p[t] >= 0){
				ans++;
				k -= p[t];
				t += 1;
			}else{
				break;
			}
			
		}
		tot = max(ans,tot);
	}
	cout << tot << endl;
	return 0;
}
