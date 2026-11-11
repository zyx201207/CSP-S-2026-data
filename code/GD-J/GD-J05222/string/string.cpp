#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	char ch;
	int num;
}st[200001];
stack<node> st1, st2;
int n, a[200001], cnt, cnt1, sum, sum1, ans;
char c[200001];
string s, s1;
signed main(){
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		sum += a[i];
		if (c[i] == st[cnt].ch){
			st[cnt].num += a[i];
		}
		else{
			st[++cnt].num = a[i];
			st[cnt].ch = c[i];
		}
	}
	if (cnt == 1){
		cout << 0;
		return 0;
	}
	if (sum <= 3e4){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= a[i]; j++){
				s += c[i];
			}
		}
		s1 = s;
		reverse(s1.begin(), s1.end());
		if (s1 == s){
			cout << 0;
			return 0;
		}
		for (int i = 0; i <= s.size(); i++){
			if (s[i] != s1[i]){
				cnt1++;
			}
		}
		cout << cnt1 / 2;
		return 0;
	}
	n = cnt;
	cnt = 1;
	while (cnt <= n && sum1 < sum / 2){
		if(sum1 + st[cnt].num <= sum / 2){
			st1.push({st[cnt].ch, st[cnt].num});
			sum1 += st[cnt].num;
			st[cnt].num = 0;
		}
		else{
			st1.push({st[cnt].ch, sum / 2 - sum1});
			st[cnt].num -= sum / 2 - sum1;
			sum1 += (sum / 2 - sum1);
			break;
		}
		cnt++;
	}
	cnt = n;
	while (cnt >= 1 && st[cnt].num != 0){
		st2.push({st[cnt].ch, st[cnt].num});
		st[cnt].num = 0;
		cnt--;
	}
	while(!st1.empty() && !st2.empty()){
		node p = st1.top();
		st1.pop();
		node q = st2.top();
		st2.pop();
		if (p.num > q.num){
			st1.push({p.ch, p.num - q.num});
			p.num = q.num;
		}
		if (q.num > p.num){
			st2.push({q.ch, q.num - p.num});
			q.num = p.num;
		}
		if (p.ch != q.ch){
			ans += p.num;
		}
	}
	cout << ans;
	return 0;
}
