#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200010];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    if(m == 1){
        cout << a[n];
    }else if(m == 2){
        int maxn = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                maxn = max(maxn, a[i]&a[j]);
            }
        }
        cout << maxn;
    }
    return 0;
}
