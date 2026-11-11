#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
    freopen("crystal.in", r, stdin);
    freopen("crystal.out", w, stdout);
    int n, m;
    int sum = 0;
    int g = 0;
    cin >> n >> m;
    int c = n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int o = a[i - 1];
        if(o > a[i]){
            a[i - 1] = a[i];
            a[i] = o;
        }
    }
    for(int j = 1;j <= n;++j){
        for(int i = 1;i <= n;++i){
            int s = a[c] - a[i];
            a[i] += s;
            m -= s;
            if(s == 0) g++;
            if(m == 0) break;
        }
        c = c - 1;
        b[j] == g;
    }
    for(int i = 1;i <= n;++i){
        sum = max(sum, b[i]);
    }
    cout << sum;
    return 0;
}