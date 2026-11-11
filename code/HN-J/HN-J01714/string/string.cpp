#include <bits/stdc++.h>
using namespace std;

int n, num, cnt;
struct node{
	int num;
	char c;
}a[200005];
queue<node> str;
deque<node> str2;

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].num >> a[i].c;
		if(a[i].c == a[i - 1].c){
			n--;
			i--;
			a[i - 1].num += a[i].num;
			a[i].num = 0;
			a[i].c = ' ';
		}
		num++;
		str.push({a[i].num, a[i].c});
	}
	if(n == 1){
		cout << 0;
		return 0;
	}
	if(num == 1){
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		node u = str.front();
		int x = u.num / 2;
		if(!str2.empty()){
			node v = str2.back();
			if(v.c == u.c){
				str2.pop_back();
				if(v.num != u.num){
					str2.push_back({u.num + v.num, u.c});
				}
			}
		}
		else {
			str2.push_back({x, u.c});
		}
	}
	cout << str2.size();
//	long long ans = 0;
//	for(int i = 0;i <= str2.size();i++){
//		node kkk = str2.front();
//		str2.pop_front();
//		ans += kkk.num;
//		cout <<1;
//	}
//	cout << ans;
	return 0;
}
/*
aabbc

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


*/

