#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int a[N], c[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++){
		int b[N];
		int k = 1;
		b[1] = a[i];
		for (int j = i+1; j <= n; j++){
			for (int x = 1; x <= k; x++){
				if (b[x] == a[k]){
					int asdf = k;
					for (int y = x+1; y <= asdf; y++)k--;
				}
				else{
					b[k++] = a[i];
				}
			}
		}
//		cout << k << endl;
		for (int j = 1; j <= k; j++){
			c[b[i]]++;
		}
	}
	for (int i = 1; i <= m; i++)cout << c[i] << ' ';
	return 0;
}
//估分100+100+[0, 50]+[0, 24]=[200, 274] 
//T1简单模拟，T2字符串，T3疑似背包dp？T4感觉是道需要优化的模拟 
//要是T3是dp的话分数线不会太高 
//昨晚上我在洛谷发的猜测为橙橙黄绿
//真正做了感觉是橙（下位）橙（上位）黄（中位）绿（我也不知道）
//听天由命吧 
