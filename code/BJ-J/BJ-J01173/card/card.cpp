#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010], b[300010];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[a[i]] = max(b[a[i]], n - i + 1);
    }
    if(m == 1){
        cout << n;
        return 0;
    }
    if(m == 2){
        long s1 = 0, s2 = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == a[n]){
                if(a[i] == 1) s1++;
                else s2++;
            }else{
                s1++;
                s2++;
            }
        }
        cout << s1 << " " << s2;
        return 0;
    }
    for(int i = 1; i <= m; i++){
        cout << b[i] << " ";
    }
    return 0;
}
