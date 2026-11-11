#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
//fight for the 7 gou. 
//my second S ended with failures.
const int N = 5e5 + 10;
ll n, m;
ll a[N], sum[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 1, r = 1, ans = 1;
	while(r <= n){
		while(m < a[r] * (r - l + 1) - sum[r] + sum[l - 1]){
//			mn = min(a[r] - (r - l + 1) - sum[r] - sum)
			l++;
		}
//		cout << l << ' ' << r << '\n';
		ans = max(r - l + 1, ans);
		r++;
	}
	cout << ans;
	return 0;
} 
/*
怎么又叫这个名字。
n个a_i，m次操作，每次使一个位置+1
问最多能使多少个位置相同 
对于每一个位置，考虑前面有多少个位置能加到这里 
简单题 
5 5
1 2 4 8 9
怎么第四个错了？？ 
前缀和写错了。
14:43 pass all big examples 
[183,?]
应该不能上200了... 
it's just a normal score in my mo ni sai.
what can i say, it's impossible for me to get 1= in CQ. 

i do not duipai, i hope all of my code is correct.

will i afo?

*/
