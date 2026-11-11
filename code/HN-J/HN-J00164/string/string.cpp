#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pi pair<int,int>
#define mini pi,vector<pi>,greater<pi>
#define p_q priority_queue
#define fs first
#define se second
using namespace std;
const ll N = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll n;
ll a[N];
char c[N];
string s;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin); freopen("string.out","w",stdout);

	cin >> n;
	ll maxn = -inf;
	for(ll i = 1;i <= n;i++) cin >> a[i] >> c[i], maxn = max(maxn, a[i]);
	
	ll ans = 0, pre = 0, p = -1;//1 = i 0 = j
	
	if(maxn * n <= 9e8){// 68'+
		for(ll i = 1;i <= n;i++){
			for(ll j = 1;j <= a[i];j++) s += c[i]; 
		}
		for(ll i = 0, j = s.size() - 1;i < j;i++, j--){
			if(s[i] != s[j]) ans++;
		}
	}else{
		for(ll i = 1, j = n;i < j;i++, j--){
			if(c[i] == c[j]){
				if(a[i] > a[j]){
					ans += a[i] - a[j];
					a[j - 1] -= (a[i] - a[j]); 
				}else{
					ans += a[j] - a[i];
					a[i + 1] -= (a[j] - a[i]); 
				}
			}else{
				ans += max(a[i], a[j]);
				if(a[i] > a[j]){
					a[j - 1] -= (a[i] - a[j]); 
				}else{
					a[i + 1] -= (a[j] - a[i]); 
				}
			}
		}
	}
	
	
	cout << ans;

	return 0;
}

