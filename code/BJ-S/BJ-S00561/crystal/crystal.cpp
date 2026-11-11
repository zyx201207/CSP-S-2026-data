#include<iostream>
#include<stdio.h>
using namespace std;

long long n, m, ans;
long long a[500010];

bool spe(){
    int cha = a[2] - a[1];
    for(int i = 2; i <= n; i++){
        if(a[i] - a[i-1] != cha){
            return 0;
        }
    }
    return 1;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    if(spe()){
        ans = 1;
        int c = a[2] - a[1];
        int t = c;

        while(m >= t && ans < n){
            m -= t;
            ans++;
            t += c;
        }

        cout << ans << endl;
        return 0;
    }

    cout << 0 << endl;
    return 0;
}
