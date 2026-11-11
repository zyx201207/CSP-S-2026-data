#include <iostream>
#include <cstring>
using namespace std;
int a[(int)(5e5 + 1)], b[(int)(3e5 + 100)], pos[(int)(3e5 + 1)], ans[(int)(3e5 + 1)]; 
int main(){
	/*
	朴素算法:
	循环 n 次，使用数组 b 进行模拟
	使用一个数组 pos 存储每张牌的位置
	插牌时如果 pos[k] 不为0，则清空 k 以后所有牌的 pos[]，并将指针设回 pos[k]
	否则根据指针放入数组 b 中并记录 pos[k] 
	每局结束后根据指针倒序枚举，为 ans[]++ 
	*/
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int cnt;
	for (int i = 1; i <= n; i++){
		memset(pos, 0, sizeof(pos));
		cnt = 0;
		for (int j = i; j <= n; j++){
			if (pos[a[j]]){
				for (int k = (pos[a[j]] + 1); k <= cnt; k++)
					pos[b[k]] = 0;
				cnt = pos[a[j]];
			}else{
				b[++cnt] = a[j];
				pos[a[j]] = cnt;
			}
		}
		for (int j = cnt; j; j--)
			ans[b[j]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
}
