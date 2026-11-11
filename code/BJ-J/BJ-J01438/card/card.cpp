#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int len = 0;
        for(int j = i;j <= n;j++){
            for(int ii = i;ii <= len;ii++){
                if(b[ii] == a[j]){
                    len -= ii - i + 1;
                }
            }
            len++;
            b[len] = a[j];
        }
        int d[500010] = {0};
        for(int j = 1;j <= len;j++){
            d[b[j]] = 1;
        }
        for(int j = 1;j <= m;j++){
            c[j] += d[j];
        }
    }
    for(int i = 1;i <= m;i++){
        cout << c[i] << ' ';
    }
    return 0;
}
