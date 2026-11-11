#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int MAXM = 300005;
bool mark[MAXN];
int n , m , a[MAXN] , pos[MAXM] , f[MAXN];
void update(int from) {
	memset(pos , 0 , sizeof(pos));
	memset(mark , false , sizeof(mark));
	int total_marked = 0;
	for(int i = from; i <= n; i++) {
		if(pos[a[i]] == 0) pos[a[i]] = i; //若当前数字没出现过，设置它的最后一次位置为i
		else {	
			for(int j = pos[a[i]]; j <= (i - 1); j++) mark[j] = true;
			pos[a[i]] = i; //更新位置 
		} 
	}
	for(int i = from; i <= n; i++) {
		if(pos[a[i]] != 0 && !mark[i]) {
			f[a[i]] ++; //如果这个数的最后一次出现位置不等于零，且这个数字没有被标记为空，则最后留有点数为a[i]的牌 
		}
	}
}
int main() {
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	update(1);
	for(int i = 1; i <= n; i++) update(i); //更新频率 
	for(int i = 1; i <= m; i++) cout << f[i] << " "; //输出频率
	return 0;
}
