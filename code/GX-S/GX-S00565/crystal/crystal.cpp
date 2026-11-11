#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n, m, a[N], b[N], j, ans, k;
long long cnt;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= n/2; i++){
        for(int j = 1;j <= n-1; j++){
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
	}

	for(int i = 1; i <= n-1; i++){
		j++;
		b[j] = a[i+1]-a[i];
	}

	for(int i = 1; i <= n-1; i++){
        k = 1;
        cnt = 0;
        for(int j = i; j <= n-1; j++){
            cnt += b[j]*j;
            if(cnt > m){
                if(k > ans) ans = k;
                break;
            }
            else k++;
        }
	}

	cout << ans << endl;
	return 0;
}
