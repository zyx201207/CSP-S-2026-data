#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int sum[500010],a[500010];
int b[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i = n; i > 0; i--){
        if(sum[a[i]] != 0){
            continue;
        }
        sum[a[i]] = i;
    }
    for(int i = 1;i <= n; i++){
         x = i;
        while(x <= n){
            if(sum[a[x]] == 0){
                b[a[x]] ++;x++;
                continue;
            }
            b[a[x]] ++;
            x = sum[a[x]]+1;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << b[i] << " ";
    }
    return 0;
}
