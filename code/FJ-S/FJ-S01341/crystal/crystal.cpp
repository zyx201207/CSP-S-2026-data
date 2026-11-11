#include<bits/stdc++.h>
#define int long long
using namespace std;
int n , tn , m , b[500010] , mx;
struct node{
	int x , num;
}a[500010];
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tn >> m;
	for (int i = 1; i <= tn; i++){
		cin >> b[i];
	}
	sort(b + 1 , b + tn + 1);
	b[0] = LLONG_MAX;
	for (int i = 1; i <= tn; i++){
		if (b[i - 1] != b[i]){
			n++ , a[n].x = b[i];
		}
		a[n].num++;
	}
//	for (int i = 1; i <= n; i++){
//		cout << a[i].x << " " << a[i].num << "\n";
//	}
	for (int i = 1; i <= n; i++){
		int sum = 0 , cnt = 0;
		for (int j = i; j >= 1; j--){
			if (sum + a[i].x - a[j].x > m){
				break;
			}
			if (sum + (a[i].x - a[j].x) * a[i].num > m){
				cnt += (m - sum) / (a[i].x - a[j].x);
				break;
			}
			cnt += a[j].num;
			sum += (a[i].x - a[j].x) * a[j].num;
			//cout << sum << "" << cnt << " ";
		}
		mx = max(mx , cnt);
		//cout << mx << "\n";
	}
	cout << mx;    
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
