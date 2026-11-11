#include<bits/stdc++.h>
using namespace std;
int n, m, maxx = 0;
int L[200020], R[200020];
int a[200020][31];
long long lr[200020];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        lr[i] = x;
		int len = 0;
        while(x){
            a[i][++len] = x & 1;
            x /= 2;
        }
        maxx = max(maxx, len);
        L[i] = i - 1;
        R[i] = i + 1;
    }
    L[0] = 0, R[0] = 1;
    L[n + 1] = n, R[n + 1] = n + 1;
    for(int i = maxx; i >= 1; i--){
		int cnt = 0;
        int l = 0;
        while(1){
            l = R[l];
            if(l > n) break;
            if(a[l][i]) cnt++;
        }
        if(cnt >= m){
            l = 0;
            while(1){
                l = R[l];
				if(l > n) break;
                if(a[l][i] == 0){
                    L[R[l]] = L[l];
                    R[L[l]] = R[l];
                }
            }
        }
    }
    int i = 0, cnt = 1;
    long long ans = lr[R[i]];
    while(cnt <= m){
        i = R[i];
        if(i > n) break;
        cnt++;
        ans = ans & lr[i];
    }
    cout << ans;
}
