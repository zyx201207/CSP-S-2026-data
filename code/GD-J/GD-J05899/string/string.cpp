#include<bits/stdc++.h>
using namespace std;
struct st{
	int x;
	char c;
}a[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].c;
	int l = 1, r = n;
	long long cnt = 0;
	while(l <= r){
		int mini;
		int minn = min(a[l].x, a[r].x);
		if(a[l].x < a[r].x) mini = l;
		else mini = r;
		if(a[l].c != a[r].c) cnt += a[mini].x;
		a[l].x -= minn;
		a[r].x -= minn;
		if(a[l].x <= 0) l++;
		if(a[r].x <= 0) r--;
	}
	cout << cnt;
	return 0;
}
