/*
#include<bits/stdc++.h>
using namespace std;
const int N = 50005;
long long n, ans, cnt;
long long m;
int a[50005];
int main() {


	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ans = 0;
	cin >> n >> m;
	int combo = 0;

	for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a, a+n+1);
	for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] = a[i-1]){
            combo++;
            cnt = (cnt>=combo) ? cnt : combo;
        }
        else combo = 0;
	}

	for(int i = 1; i <= m; i++){

		dp[0] = cnt;
		for(int j = 1; j <= n; j++){
            int x = 0;
            if (a[j+1] - a[j]) dp[i] += ;
		}

	}
	cout<<ans;


	return 0;
}
*/


#include<bits/stdc++.h>
using namespace std;
long long m, d, sum, a[50014];
long long ans = 0;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);///
    int n;  cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a, a+n+1);///
    d = a[2] - a[1];
    if(m < d){
        cout<<1;
        return 0;
    }
    if(d == 0){
        cout<<n;
        return 0;
    }
    while(1){
        ans += 1 ;
        sum = d*(ans*(ans-1)) / 2;
        if(sum == m) break;

        if(sum > m) {
            ans -= 1;
            break;
        }
    }
    if(ans > n) cout<<n;
    else cout << ans;

    return 0;
}

//dp[i]:进行i次操作后，最多能消耗多少水晶
//dp[i] = dp[i-1] + x
//x:当前操作消耗水晶数量
//ans = n - now~dispeled
//A.P.(16~18)
//sum = 0 + n(n-1)*d/2 < operation.

