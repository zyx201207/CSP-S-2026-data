//GZ-J00395  贵阳市第三实验中学  闫张玴
#include <bits/stdc++.h> 
using namespace std;
const int N = 5e5+10, M = 3e5+10;
int n, m;
int p[M], li[N], a[N], ans[M];

int find(int k) {
	for(int i=0; i<=n; i++) {
		if(li[i] == k) return i;
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int J=1; J<=n; J++) {
		//初始化
		for(int i=0; i<=n; i++) li[i] = i+1;
		for(int i=1; i<=m; i++) p[i] = 0;
		for(int i=J; i<=n; i++) {
			if(p[a[i]] == 0) {			//还未出现过
				p[a[i]] = i;
			} else {					//可以消卡牌 
				int fc = find(p[a[i]]);					//找到头指针 
				li[fc] = i;								//将它指向当前位置，即删除中间卡牌 
				for(int j=1; j<=m; j++) {
					if(p[j] > fc && p[j] < i) p[j] = 0;	//被夹中间消掉的 
				}
				p[a[i]] = i;			//更新自身位置 
			}
		} 
		for(int i=1; i<=m; i++){
			if(p[i] != 0) ans[i]++;
		}
	}
	for(int i=1; i<=m; i++) cout << ans[i] << " ";
	return 0;
}
