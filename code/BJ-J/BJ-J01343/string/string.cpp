#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long ans = 0;
    for(int i=1;i<=n;i++)
        cin >> a[i] >> c[i];
    int p = 1, q = n;
    while(p != q){
        if(a[p] == a[q]){
            if(c[p] != c[q])
                ans += a[p];
            p++;q--;
        }
        if(a[p] > a[q]){
            if(c[p] != c[q])
                ans += a[q];
            a[p] -= a[q];
            q--;
        }
        if(a[p] < a[q]){
            if(c[p] != c[q])
                ans += a[p];
            a[q] -= a[p];
            p++;
        }
    }
    cout << ans;
    return 0;
}
