/*
08:55 开T2
08:57 前缀和应该可以
09:03 思路挂了
09:16 无思路
09:18 希望能有个三等，感觉要AFO了，希望上迷惑行为大赏
09:54 已放弃
10:33 决定打暴力
10:39 完成，预计68分
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,a[200005];
char c[200005];
ll ans;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	// freopen("string1.in","r",stdin);
	// freopen("string1.out","w",stdout);

	// freopen("string2.in","r",stdin);
	// freopen("string2.out","w",stdout);

	// freopen("string3.in","r",stdin);
	// freopen("string3.out","w",stdout);
	// 炸了

	// freopen("string4.in","r",stdin);
	// freopen("string4.out","w",stdout);

	// freopen("string5.in","r",stdin);
	// freopen("string5.out","w",stdout);
	// 炸了

	// freopen("string6.in","r",stdin);
	// freopen("string6.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i];j++) s += c[i];
	}
	for(int i = 0;i < s.size() / 2;i++){
		if(s[i] != s[s.size() - i - 1]) ans++;
	}
	cout << ans;
	cout << '\n';
	return 0;
}