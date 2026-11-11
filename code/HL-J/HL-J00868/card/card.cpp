#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[500010];
int t[500010];
int tt;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int ti=1;ti<=n;ti++){
            tt=0;
        for(int i=ti;i<=n;i++){
            bool flag=0;

            for(int j=1;j<=tt;j++){
                if(t[j]==a[i]){
                    tt=j;
                    flag=1;
                    break;
                }
            }
            if(!flag){
                t[++tt]=a[i];
            }
        }
        for(int i=1;i<=tt;i++){
            ans[t[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
