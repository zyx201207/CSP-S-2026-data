#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
struct state{
    int sum;
    char c;
}a[N];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].sum >> a[i].c;
    }
    int L = 1, R = n;
    long long ans = 0;
    while(L < R){
        int minx = min(a[L].sum, a[R].sum);
        if(a[L].c != a[R].c){
            ans += minx;
        }
        a[L].sum -= minx;
        a[R].sum -= minx;
        if(a[L].sum == 0) L++;
        if(a[R].sum == 0) R--;
    }
    cout << ans << '\n';
    return 0;
}