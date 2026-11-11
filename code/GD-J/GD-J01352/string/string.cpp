#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans;
struct node{
	char x;
	int y;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		char x;
		int y;
		cin >> y >> x;
		if(a[m].x == x) a[m].y += y;
		else a[++ m] = (node){x, y};
	}
	int l = 1, r = m;
	while(l < r){
		if(a[l].x != a[r].x) ans += min(a[l].y, a[r].y);
		if(a[l].y > a[r].y) a[l].y -= a[r].y, a[r].y = 0;
		else a[r].y -= a[l].y, a[l].y = 0;
		if(a[l].y == 0) l ++;
		if(a[r].y == 0) r --;
	}
	cout << ans << endl;
	return 0;
}
