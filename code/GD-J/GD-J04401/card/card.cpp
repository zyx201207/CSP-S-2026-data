#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],c[500010],ans[300010],index_now = 1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){//第几局
		index_now = 1;
		for (int j = i;j <= n;j++){//放入的卡牌编号 
			for (int k = 1;k <= index_now;k++){//查找相同卡牌
				if (c[k] == a[j]){
					for (int p = k;p <= index_now;p++){//收回卡牌 
						c[p] = 0;
					}
					index_now = k;
					break;
				}
			}
			c[index_now] = a[j];
			index_now++;
		}
		for (int j = 1;j < index_now;j++){
			ans[c[j]]++;
		}
	}
	for (int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
