#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n, a[N], cnt[N];//牌数&&局数，牌，计数 
int z[N], t, mx;//桌面，桌计数，牌中最大值 
 
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	//输入 
	cin >> n;
	for(int i = 1;i <= n;i++){
	cin >> a[i];	
	mx = max(mx, a[i]);
	}
	
	//模拟 
	for(int i = 1;i <= n;i++){//n局 
	t = 0;
		for(int j = i;i <= n;j++){//i - n张牌 
			bool p = 0;
			for(int k = 1;k <= n;k++){//有没有相等的  
				if(a[j] == a[k]){//相等 
					p = 1;
					t = k;//收牌 
					z[t] = a[j];//放k
					break;
				}
			}
			if(!p){//无相等，往右边放牌 
				z[++t] = a[j];
			}
		}
		for(int j = 1;j <= t;j++) cnt[z[i]]++;//统计牌 
	}
	for(int i = 1;i <= mx;i++) cnt[z[i]]++;//统计牌 
	return 0; 
} 
/*
n 局  相互独立 的游戏。每局开始前，所有牌按原顺序放回牌堆，并清空桌面。
过程: 
在第i局中，依次打出第 i张到第 n张牌
桌上的牌始终从左到右排成一行。打出一张点数为 k 的牌时：
没有k：放最右 
有k：收走桌面上点数为k 的牌及其右侧的所有牌，再把这张牌放在最右端。收走的牌本局中不再使用。

最后一张牌打出后，本局游戏结束。
在所有n 局游戏中，有多少

每局结束时桌面上留有点数为i 的牌。
*/
