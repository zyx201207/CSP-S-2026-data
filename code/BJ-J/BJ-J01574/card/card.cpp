#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 1;
int m , n;
int a[maxn] , vis[maxn] , b[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","W",stdout);
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        vis[a[i]]++;
    }
    if(m == n){
        b[a[1]] = 1;
        for(int i = 2; i <= m; i++){
            b[a[i]] = b[a[i - 1]] + 1;
        }
    }else{
        for(int i = 1; i <= n; i++){
            cout << m << " ";
        }
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cout << b[i] << " ";
    }
    return 0;
}
