#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 10;
ll a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int mid = (1 + n) / 2;
    int ans = 1;
    int idx = mid + 1;
    while(a[idx] == a[mid]){
    	ans++;
    	idx++;
	}
	int idx2;
    for(int i = mid - 1; i >= 1; i--){
        if(m > 0 && m >= a[mid] - a[i]){
            m -= a[mid] - a[i];
            a[i] = a[mid];
            ans++;
            idx2 = i;
        }
    }
    while(m >= ans){
    	for(int i = 1; i <= idx; i++){
    		m--;
    		a[i]++;
		}
		int idx3 = idx + 1;
		while(a[idx3] == a[idx]){
			ans++;
			idx3++;
		}
		idx = (idx3 == idx + 1 ? idx : idx3);
	}
    cout << ans;
    return 0;
}
