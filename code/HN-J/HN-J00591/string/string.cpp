#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct P{
	int x;
	char c;
}a[200010];
int n, m, cnt, num;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int t = 1;t <= n;t++){
		cin >> a[t].x >> a[t].c;
		num += a[t].x;
//		t[a[i].c] += a[i].x;
//		maxa = max(t[a[i].c], maxa);
	}
//	if(maxa == num){
//		cout << 0;
//		return 0;
//	}
	int s = 0, i = 1;
	if(num % 2 == 0){
		while(1){
			if(a[i].x - a[n - s].x == 0){
				if(a[i].c == a[n - s].c){
					cnt += a[i].x;
				}
				a[n - s].x = 0;
				a[i].x = 0;
				s++;
				i++;
			}else if(a[i].x - a[n - s].x < 0){
				if(a[i].c == a[n - s].c){
					cnt += a[i].x;
				}
				a[n - s].x = a[n - s].x - a[i].x;
				a[i].x = 0;
				i++;
			}else if(a[i].x - a[n - s].x > 0){
				if(a[i].c == a[n - s].c){
					cnt += a[n - s].x;
				}
				a[i].x = a[i].x - a[n - s].x;
				a[n - s].x = 0;
				s++;
			}
			if(i + 1 == n - s){
				break;
			}
		}
		cout << num / 2 - cnt;
		return 0;
	}
	while(1){
		if(i == n - s){
			if(a[i].x > 0){
				cnt += a[i].x / 2;
			}
			break;
		}
		if(a[i].x - a[n - s].x == 0){
			if(a[i].c == a[n - s].c){
				cnt += a[i].x;
			}
			a[n - s].x = 0;
			a[i].x = 0;
			s++;
			i++;
		}else if(a[i].x - a[n - s].x < 0){
			if(a[i].c == a[n - s].c){
				cnt += a[i].x;
			}
			a[n - s].x = a[n - s].x - a[i].x;
			a[i].x = 0;
			i++;
		}else if(a[i].x - a[n - s].x > 0){
			if(a[i].c == a[n - s].c){
				cnt += a[n - s].x;
			}
			a[i].x = a[i].x - a[n - s].x;
			a[n - s].x = 0;
			s++;
		}
	}
	cout << num / 2 - cnt;
	return 0;
}
//20
//1 a
//2 b
//1 c
//2 d
//1 n
//2 a
//1 a
//1 a
//1 a
//2 s
//3
//a
//2 d
//3 f
//4 f
//5 s
//6 b
//6 c
//3 c
//4 c
//5 d
