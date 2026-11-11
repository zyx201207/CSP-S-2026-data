//GZ-J00564  毕节七星关东辰实验学校  李浩辰 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e8 + 10;
bool f[27];
ll n, ans[27], p, sum, t, ts, l;
bool cmp(ll x, ll y){
	return x > y;
}
char s[maxn];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		ll a; char c;
		cin >> a >> c;
		for(int i = 1; i <= a; i++){
			s[l] = c;
			l++;
		}
		ans[c - 96] += a;
		sum += a;
		if(!f[c - 96]){
			p++;
			f[c - 96] = true;
		}
	}
	t = sum / 2;
	for(int i = 0; i < l / 2; i++){
		if(s[i] == s[l - i] && s[i] != s[t + 1]) ts += 2;
		else if(s[i] == s[t - 1]) ts++;
	}
	sort(ans + 1, ans + 27, cmp);
	if(p == 1) cout << "0";
	else if(p == 2) cout << min(sum - ts, ans[p]);
	else{
		if(sum % 2 == 0){
			if(s[t] == s[t + 1]) cout << min(sum - ts, t - 1);
			else if(s[t + 1] == s[t + 2]) cout << min(sum - ts, t);
			else cout << min(sum - ts, t + 1);
		}else cout << min(sum - ts, t);
	}
	return 0;
}
