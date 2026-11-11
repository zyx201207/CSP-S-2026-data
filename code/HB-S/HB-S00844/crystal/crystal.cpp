#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10;
long long a[M], b[M], n, m, tt, cnt;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long left = 1, right = 1;
    while(right <= n && left <= n){
        tt = m;
        tt = tt - (right - left) * (a[right + 1] - a[left]);
        if(tt >= 0){
            right++;
            cnt = max(cnt, (right - left + 1));
        }
        else{
            while(tt - (right - left + 1) * (a[right + 1] - a[left]) <= 0){
                left++;
                tt += a[right + 1] - a[left];
            }
        }
    }
    cout << cnt;
    return 0;
}
