#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
struct node{
	int x,ad;
}a[200005];
bool cmp(node o,node y){
	if(o.ad != y.ad) return o.ad > y.ad;
	if(abs(o.x - y.x) & 1) return (o.x & 1) > (y.x & 1);
	return o.x > y.x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	bool f = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i].x;
		int x = 1;
		int ra = a[i].x;
		int cnt = 0;
		if(i >= 2 && a[i].x - a[i-1].x != 1) f = 0;
		while(ra){
			if(ra & 1) cnt++;
			ra >>= 1;
		}
		a[i].ad = cnt;
	}
	if(f){
		cout << n - m;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ans = a[1].x;
	for(int i = 2;i <= m;i++){
		ans &= a[i].x;
	}
	cout << ans;
	return 0;
}
