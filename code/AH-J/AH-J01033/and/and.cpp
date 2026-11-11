#include<bits/stdc++.h>
using namespace std;
int a[200005];
int awy(int x,int y){
	int ans = 0;
	cin >> x >> y;
	int k = 0,xx = x;
	while(xx != 0){
		xx /= 2;
		k ++;
	}
	//cout << k << ' ';
	for(int i = 1;i <= k;i ++){
		int now = x%2,dow = y%2;
		x/=2;
		y/=2;
		//cout << now << ' ' << dow << endl;
		ans += ((now & dow) << (i - 1));
	}
	return ans;
}
bool cmp(int x,int y){
	int xc = 0,yc = 0;
	while(x != 0){
		if(x % 2 == 1) xc ++;
		x /= 2;
	}
	while(y != 0){
		if(y % 2 == 1) yc ++;
		y /= 2;
	}
	return xc <= yc;
}
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		//int t;
		//cin >> t;
		
		cin >> a[i];
		//dp[i] = 2147483647;
	}
	sort(a + 1,a + 1 +n,cmp);
	int ans1 = 2147483647;
	for(int i = n;i >= n - m + 1;i --){
		ans1 = awy(ans1,a[i]);
	}
	sort(a + 1,a + 1 +n);
	int ans2 = 2147483647;
	for(int i = n;i >= n - m + 1;i --){
		ans2 = awy(ans2,a[i]);
	}
	cout << max(ans1,ans2);
	return 0;
}

