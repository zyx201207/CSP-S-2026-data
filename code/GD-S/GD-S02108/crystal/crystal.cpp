#include<bits/stdc++.h>
using namespace std;

#define MAXN 500007

long long n, m, a[MAXN], cnt_num = -1;
unsigned long long cnt_plus = 0;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	a[0] = 0;
	
	for(int i = 1; i <= n; i++){//diff_i refers to a[i] - a[i - 1]
		long long diff = a[i] - a[i - 1];
		cnt_plus += diff * (i - 1);
		if(cnt_plus > m){
			cnt_num = i - 1;
		}
	}
	
	cout << cnt_num;
	return 0;
}



