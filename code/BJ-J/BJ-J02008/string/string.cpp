#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x;
	char y;
}a[200005];
int n , len , ans;
signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].x >> a[i].y;
		len += a[i].x;
	}
	int l = 1 , r = n;
	while(l < r){
		int tmp = min(a[l].x , a[r].x);
		if(a[l].y != a[r].y){
			ans += tmp;
			//cout << tmp << endl;
		}
		a[l].x -= tmp;
		a[r].x -= tmp;
		if(a[l].x <= 0)l++;
		if(a[r].x <= 0)r--;
	}
	cout << ans;
	return 0;
}