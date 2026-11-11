#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,chang = 0;
	cin >> n >> m;
	long long a[n] = {0},b[n][n] = {0},c[m+1] = {0}; //a[纸牌从上到下的数],b[场次][该场次的纸牌排序],c[记录大小为i的纸牌出现次数] 
	for (long long i = 0; i < n; i++) cin >> a[i]; //输入从上到下的数 
	for (long long i = 0; i < n; i++) { //游戏场数 
		for (long long j = i; j < n; j++) { //纸牌放置顺序 
			for (long long k = 0; k < j; k++) { //判断前面的是否有重复 
				if (b[i][k] == a[j]) { //发现重复 
					for (long long l = k; l <= chang; l++) b[i][l] = 0;//将前面重复的那张牌后面全部清零 
					chang = k; //将长度设为重复数的位置 
					break;
				}
			}
			b[i][chang] = a[j];
			chang++; //把新的数加在后面 
		}
		chang = 0;
	}
	for (long long i = 1; i <= m; i++) { //循环每个数，寻找次数 
		for (long long j = 0; j < n; j++) { //循环遍历场次 
			for (long long k = 0; k < n; k++) { //查找该场次的纸牌 
				if (b[j][k] == i) c[i]++; //增加大小为i的纸牌出现的次数 
			}
		}
	}
	for (long long i = 1; i <= m; i++) cout << c[i] << " ";
	return 0;
}
