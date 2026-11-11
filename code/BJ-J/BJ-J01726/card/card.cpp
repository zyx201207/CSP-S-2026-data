#include<bits/stdc++.h>
using namespace std;

int a[500005] = {0},p[500005] = {0},k[300005] = {0},ans[300005] = {0};

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,c = 1;
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++){
        for (int j = i;j <= n;j++){
            if (p[c] != 0) k[p[c]] = 0;
            if (k[a[j]] == 0){
                p[c] = a[j];
                k[a[j]] = 1;
                c++;
            }
        }
        for (int i = 1;i < c;i++){
            ans[p[i]]++;
        }
    }
    for (int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}