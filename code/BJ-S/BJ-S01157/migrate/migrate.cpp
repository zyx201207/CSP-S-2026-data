#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3;
int a[N],t,o,n,m,f[N][N][10];
int l[N],r[N],ans;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    cin>>o>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int nn = 1<<n;
        for(int i=1;i<nn;i++){
            int ci = i;
            int rid = 0,cnt=0,si = 0;
            bool flag = 1;
            while(ci){
                ++cnt;
                if(ci & 1){
                    si++;
                    if(!r[i])
                        r[i] = cnt;
                    l[i] = cnt;
                    if(a[cnt] - a[rid] > m && rid)
                        flag = 0;
                    rid = cnt;
                }
                ci >>= 1;
            }
            if(l[i] == r[i])
                flag = 0;
            if(flag)
                f[l[i]][r[i]][si] ++;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=2;k<=n;k++)
                    if(f[i][j][k]){
                        if(f[i][j][k] == 2)
                            ans ++;
                        break;
                    }
            }
        }

        cout<<ans<<"\n";
        for(int i=0;i<=nn;i++)
            l[i] = r[i] = 0;
        ans = 0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                for(int k=0;k<=n;k++)
                    f[i][j][k] = 0;
    }
    return 0;
}
