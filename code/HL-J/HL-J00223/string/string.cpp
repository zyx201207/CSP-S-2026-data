#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int cnt;
	char ch;
} a[200010];
signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i].cnt >> a[i].ch;
	int i = 1 , j = n;
	int ans = 0;
	while(i < j){
		int dis = min(a[i].cnt , a[j].cnt);
		if(a[i].ch != a[j].ch) ans += dis;
		a[i].cnt -= dis;
		a[j].cnt -= dis;
		if(!a[i].cnt) i ++;
		if(!a[j].cnt) j --;
	}
	cout << ans;
	return 0;
}
