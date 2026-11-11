#include<iostream>
#include<stdio.h>
using namespace std;

int n;
unsigned long long ans;
long long a[200010];
char c[200010];

int l, r;
long long lr, rr;
long long t;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }

    l = 0; r = n + 1;
    while(l < r){
        if(lr == 0){
            lr = a[++l];
        }
        if(rr == 0){
            rr = a[--r];
        }
        if(l >= r){
            break;
        }

        t = min(lr, rr);
        lr -= t;
        rr -= t;

        if(c[l] != c[r]){
            ans += t;
        }
    }

    cout << ans << endl;
    return 0;
}
