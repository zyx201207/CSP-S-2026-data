#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 500005;
const ll INF = 1e18;

int n;
ll m;
ll arr[N];
ll prefix[N];

bool getres(int p , int len){
	ll goal = arr[p] * len - (prefix[p] - prefix[p - len]);
	if(goal <= m){
		return true;
	}
	return false;
}

bool check(int mid){
	int res = 1;
	for(int i = n;i >= mid;i--){
		if(getres(i , mid))
			return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);	
	
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> arr[i];
	}
	
	sort(arr + 1,arr + n + 1);
	
	
	for(int i = 1;i<=n;i++){
		prefix[i] = prefix[i - 1] + arr[i];
	}
	prefix[n + 1] = prefix[n];
	
	int ans = 1;
	int l = 1 , r = n;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			ans = max(ans,mid);
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}

/*
8 7
1 2 3 4 5 6 7 8

6 0
1 2 3 4 5 6

*/
