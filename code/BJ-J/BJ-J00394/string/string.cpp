#include <bits/stdc++.h>
using namespace std;
long long x[200005];
char c[200005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> c[i];
    }
    long long cnt = 0;
    int j = 0;
    for(int i = 0; i < n - j - 1;){
        if(c[i] != c[n - j - 1]){
            cnt += min(x[i], x[n - j - 1]);
            int xx = x[i];
            x[i] -= x[n - j - 1];
            x[n - j - 1] -= xx;
        }
        else {
            int xx = x[i];
            x[i] -= x[n - j - 1];
            x[n - j - 1] -= xx;
        }
        if(x[n - j - 1] <= 0) j++;
        if(x[i] <= 0) i++;
    }
    cout << cnt;
    return 0;
}
