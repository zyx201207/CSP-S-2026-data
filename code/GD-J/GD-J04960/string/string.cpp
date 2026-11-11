#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1000;
struct ll{
	long long a;
	char b;
};
ll a[N];
int n;
long long cnt = 0;
void check(int x, int y){
	if(x == y || x > y){
		return;
	}
	int i = x, j = y;
	if(a[x].a > a[y].a){
		if(a[x].b != a[y].b){
			cnt += a[y].a;
			a[x].a -= a[y].a;
		}
		j--;
	} else if(a[x].a < a[y].a){
		if(a[x].b != a[y].b){
			cnt += a[x].a;
			a[y].a -= a[x].a;
		}
		i++;
	} else {
		if(a[x].b != a[y].b){
			cnt += a[x].a;
		}
		i++;
		j--;
	}
	check(i, j);
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].a >> a[i].b;
	}
	check(1, n);
	cout << cnt;
	return 0;
}
