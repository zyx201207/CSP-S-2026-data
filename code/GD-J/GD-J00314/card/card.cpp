#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[(int)5e5 + 5], cnt[(int)5e5 + 5], nxt[(int)5e5 + 5], _lst[(int)5e5 + 5];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool flag = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(_lst[a[i]]) nxt[_lst[a[i]]] = i;
		_lst[a[i]] = i;
		if(i != 1 && a[i] > a[i - 1]) flag = false;
	}
	if(flag){
		for(int i = 1,lst = -1;i <= n;i++){
			if(a[i] != lst){
				if(lst != -1) cout << i - 1 << ' ';
				lst = a[i];
			}
		}
	} else {
		for(int i = 1;i <= n;i++){
			for(int cur = i;cur <= n;){
				if(nxt[cur]){
					cur = nxt[cur];
				}
				else {
					cnt[a[cur++]] ++;
				}
			}
		}
		for(int i = 1;i <= m;i++) cout << cnt[i] << ' ';
	}
	return 0;
}

// 1153 我好像知道该怎么做了。。。。。。。。。但是没时间了。。。。
