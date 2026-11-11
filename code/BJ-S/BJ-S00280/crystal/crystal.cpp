#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int a[N];
int n, m;
int l;
int p, q;
int d[N];
int c[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; i++){
        d[i] = a[n] - a[i];
    }
    for(int i = n; i >= 1; i--){
        c[i] = d[i] + c[i+1];
    }
    p = q = 1;
    l = 1;
    while(p != n)
    {
        if(q < n) q++;
        while(c[p] - c[q+1] - (q-p+1) * d[q] > m) p++;
        l = max(l, q - p + 1);
        if(q == n)p++;
    }
    cout<< l;
    return 0;
}
