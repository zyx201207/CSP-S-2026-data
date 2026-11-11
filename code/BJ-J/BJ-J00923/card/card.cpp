#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], d[300005], t[500005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(m == 2){
        for(int i = 1; i <= n; i++){
            for(int j = i;j <= n; j++){
                if(a[i] != t[1] && t[1] != 0){
                    t[2] = a[i];
                }
                else if(t[1] == 0){
                    t[1] = a[i];
                }
                else if(a[i] == t[1] || a[i] == t[2]){
                    t[1] = a[i];
                    t[2] = 0;
                }
            }
            d[1] += t[1];
            d[2] += t[2];
        }
        cout << d[1] << ' ' << d[2];
    }
    return 0;
}


