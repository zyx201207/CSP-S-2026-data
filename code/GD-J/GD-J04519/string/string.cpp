#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n;
long long cnt;
struct node{
	long long num;
	char c;
}a[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].num >> a[i].c;
	}
	int l = 1, r = n;
	while (l < r){
		if (a[l].c != a[r].c){
			if (a[l].num > a[r].num){
				cnt += a[r].num;
				a[l].num -= a[r].num;
				r--;
			}
			else if (a[l].num < a[r].num){
				cnt += a[l].num;
				a[r].num -= a[l].num;
				l++;
			}
			else if (a[l].num == a[r].num){
				cnt += a[l].num;
				l++, r--;
			}
		}
		else if (a[l].c == a[r].c){
			if (a[l].num > a[r].num){
				a[l].num -= a[r].num;
				r--;
			}
			else if (a[l].num < a[r].num){
				a[r].num -= a[l].num;
				l++;
			}
			else if (a[l].num == a[r].num){
				l++, r--;
			}
		}
	}
	cout << cnt;
	return 0;
} 
