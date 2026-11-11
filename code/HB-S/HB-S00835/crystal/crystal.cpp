#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
int n ;
long long m;
int a[N];
int maxn = 0;
bool check(){
	int cha = a[2] - a[1];
	for(int i = 3;i <= n;i ++){
		if(a[i]-a[i-1] != cha)return false;
	}
	return true;
}
int make(int i){
	int t = m;
	int cnt = 0;
	for(int j = i;j >= 1;j --){
		if((t - (a[i] - a[j])) < 0)return cnt;
		t -= (a[i] - a[j]);
		cnt ++;
	}
	return cnt;
}
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out", "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)cin >> a[i];
	sort(a + 1 , a + n + 1);
	if(check()){
		int cha = a[n] - a[n-1];
		cout << (m / cha);
		return 0;
	}
	int l = 1,r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		int y = make(mid);
		if(y > maxn)l = mid , maxn = y;
		else r = mid - 1;
	}
	cout << l;
//	for(int i = 1;i <= n;i ++){
//		if(i == 1){
//			maxn = 1;
	//		continue;
	//	}
	//	if(i == 2){
	//		if((a[2] - a[1]) <= m)maxn = 2;
	//		continue;
	//	}
	//	
	//	maxn = max(cnt , maxn);
//	}
//	cout << maxn;
	return 0;
}
