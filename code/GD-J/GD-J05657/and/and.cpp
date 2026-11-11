#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, m;
int a[N];
bool flg[N];
int ans = 0;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i], flg[i] = 1;
    for(int k = 29; k >= 0; k--){
        int nw = 0;
        for(int i = 1; i <= n; i++){
            if(flg[i] && ((a[i] >> k) & 1))nw++;
        }
        if(nw < m)continue;
        ans |= (1 << k);
        for(int i = 1; i <= n; i++){
            flg[i] &= ((a[i] >> k) & 1);
        }
    }
    cout << ans;
    return 0;
}
