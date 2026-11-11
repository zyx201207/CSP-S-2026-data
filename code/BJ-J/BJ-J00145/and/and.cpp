#include<bits/stdc++.h>
using namespace std;

int n, m, maxn, ans, a[200005],sum, tmp,c[200005];


int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            c[i] = a[i];
        }
        maxn = a[k];
        c[k]= 0;
        for(int i = 2; i <= m; i++){
            ans = 0;
            for(int j = 1; j <= n; j++){
                if(maxn & c[j] > ans){
                    ans = maxn & c[j];
                    c[j] = 0;
                }
            }
            maxn = ans;
        }
        ans = maxn;
        sum = max(sum, ans);
    }
    cout << sum;
    return 0;
}
