// GZ-S00079 贵阳市第一中学 伍星恒 
// Exceptation : 100 points of 100
#include <bits/stdc++.h> 
using namespace std;
int n;
long long m;
long long a[500005];

struct node{
	int cnt;
	long long val;
}c[500005];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int x = 1;
	c[1].cnt = 1;
	c[1].val = a[1];
	for(int i = 2; i <= n; i++){
		if(a[i] == c[x].val){
			c[x].cnt ++;
		}
		else{
			c[++x].cnt = 1;
			c[x].val = a[i];
		} 
	}
	
	int l = 1, r = 1, cnt = c[1].cnt, ans = 0;
	long long cost = 0;
	while(1){ 
		while(r < x){
			long long cost2 = cost + (c[r+1].val - c[r].val) * cnt;
			int cnt2 = cnt + c[r+1].cnt;
			r++;
			if(cost2 <= m){
				cost = cost2;
				cnt = cnt2;
			}
			else{
				r--; 
				break;
			}
		}
		if(l == 1){
			ans = max(ans, cnt);
		} 
		else{
			ans = max(ans, cnt + min(c[l-1].cnt, (int)((m-cost)/(c[r].val-c[l-1].val))));
		}
		if(r == x){
			break;
		} 
		cost -= c[l].cnt * (c[r].val-c[l].val);
		cnt -= c[l].cnt;
		l ++;
	}
	cout << ans;
	return 0;
}
