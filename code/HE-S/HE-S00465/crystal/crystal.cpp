#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 5e5 + 5;
const int N = 5e5 + 5;

int n, m;
int a[N];
int pre[N];

bool check(int x){
	int l = 1, r = x;
	while(r <= n){
		int tmp = x*a[r];
		int sum = pre[r] - pre[l-1];
		if(tmp - sum <= m) return 1;
		l++;
		r++;
	}
    return 0;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	sort(a+1, a+n+1);
	
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i-1] + a[i];
	}
	
	int l = 1, r = n;
	int ans = 0;
	while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
	}

	cout << ans << endl;
	return 0;
}
