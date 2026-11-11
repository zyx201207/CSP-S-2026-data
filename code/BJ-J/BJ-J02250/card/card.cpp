#include <bits/stdc++.h>
using namespace std;
int n , m , a[500010],y = 1,q[500010],ans[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;++i){
        cin>>a[i];
    }
    for(int i = 1;i <= n;++i){
        int f[500010];
        for(int j = 1;j <= m;++j) f[a[j]] = 0;


        for(int j = i;j <= m;++j){
            if(f[a[j]] == 0){
                q[y] = a[j];
                f[a[j]] = y;
                ++y;
            }
            else{
                y = f[a[j]];
                ++y;
            }
        }
        for(int j = 1;j <= m;++j){
            if(f[j] != 0 && f[j] < y) ++ans[q[f[j]]];
        }


    }
    for(int i = 1;i <= m;++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}
