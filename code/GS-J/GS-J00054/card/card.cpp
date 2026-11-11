#include<bits/stdc++.h>
using namespace std;
const long long N = 5 * 1e5 + 5;
long long a[N], c[N], ans[N];

inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-'){
            f = -1;
            ch = getchar();
        }
    }

    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }


    long long f = 0;
    while(m--){
       memset(c, 0, sizeof(c));
       for(long long i = 1 + f; i <= n; i++){
           c[i] = a[i];
           for(long long j = 1; j <= i; j++){
               if(a[i] = c[j]){
                  for(long long k = j + 1; k <= i; k++){
                    c[k] = 0;
                  }
               }
           }
       }

       for(long long i = 1; i <= n; i++){
           for(long long j = 1; j <= m; j++){
              if(c[i] == j){
                 ans[j]++;
              }
           }
       }

       f++;
    }


    for(long long i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
