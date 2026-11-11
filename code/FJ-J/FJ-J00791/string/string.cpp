#include<bits/stdc++.h>
using namespace std;
struct ant{
	long long x;
	char y;
}a[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	if (n == 1){
		cout << 0;
		return 0;
	}
	a[0].y = 'A';
	int z = 0;
	for (int i = 1;i <= n;i++){
		int x;
		char y;
		cin >> x >> y;
		if (y == a[z].y){
			a[z].x += x;
		}
		else {
			z++;
			a[z].x = x;
			a[z].y = y;
		}
	}
	int r = 1, l = z;
	long long ct = 0;
	while (r < l){
		if (a[r].y == a[l].y){
			if (a[r].x > a[l].x){
				a[r].x -= a[l].x;
				l--;
			}
			else if (a[r].x == a[l].x){
				r++;
				l--;
			}
			else {
				a[l].x -= a[r].x;
				r++;
			}
		}
		else {
			ct += min(a[r].x,a[l].x);
			if (a[r].x > a[l].x){
				a[r].x -= a[l].x;
				l--;
			}
			else if (a[r].x == a[l].x){
				r++;
				l--;
			}
			else {
				a[l].x -= a[r].x;
				r++;
			}
		}
	}
	cout << ct;
	return 0;
}
