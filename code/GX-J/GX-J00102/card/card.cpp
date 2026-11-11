#include <bits/stdc++.h>

using namespace std;
long long n,m,a[500100],b[300100],c[500100],d[50010000],w = 1;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if(c[a[j]] != 0){
               w = c[a[j]] + 1;
            }else{
               c[a[j]] = w;
               d[w] = a[j];
               w++;
            }
            if(i == 6){
               for(int i = 1;i <= n;i++){
                cout << c[i] << " ";
            }
            cout << endl;
            for(int i = 1;i <= n;i++){
                cout << d[i] <<" ";
            }
            cout << w << endl;
            }
        }
        for(int i = 1;i < w;i++){
            b[d[i]]++;
        }
        for(int i = 0;i <= max(m,n);i++){
                d[i] = 0;
                c[i] = 0;
            }
            for(int i = 1;i <= m;i++){
                cout << b[i] <<" ";
            }
            cout << endl;
        w = 1;
    }
    for(int i = 1;i <= m;i++){
        printf("%lld ",b[i]);
    }
    return 0;
}
