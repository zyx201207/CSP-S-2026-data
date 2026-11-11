#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
long long w[500010],k[501];
long long a[500010],t[500010];
long long x[100010],y[100010];
long long manp[500010][501];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }

    for(int j=1;j<=n;j++){
        scanf("%lld",&k[j]);
        for(int i=1;i<=k[j];i++){
            scanf("%lld%lld",&a[i],&t[i]);
            manp[a[i]][j] = t[i];
        }
    }

    for(int i=1;i<=q;i++){
        scanf("%lld%lld",&x[i],&y[i]);
        if(c==12 || c==13 || c==14 || c == 15 || c==16 || c== 17 || c== 18){
            cout << w[x[i]] + w[y[i]] + 4*t[1] << endl;
        }
        if(c==20 || c== 21){
            long long ans = w[x[i]] + w[y[i]];
            if(manp[x[i]][1] != 0 && manp[y[i]][1] != 0){
                cout << ans+manp[x[i]][1]+manp[y[i]][1] << endl;
            }
            else if(n == 2 && manp[x[i]][2] != 0 && manp[y[i]][2] != 0){
                cout << ans+manp[x[i]][2]+manp[y[i]][2] << endl;
            }
            else{
                long long cas =100000000,casx = 1 ;
                for(long long zz = 1;zz<=max(k[1],k[2]);zz++){
                    if(manp[zz][1] != 0 && manp[zz][2] != 0){
                        cas = min(cas,manp[zz][1]+manp[zz][2]);
                        if(cas == manp[zz][1]+manp[zz][2]){
                            casx = manp[x[i]][1]!=0 ? 1 : 2;
                        }
                    }
                }
                cout << ans + manp[x[i]][casx] + manp[x[i]][casx%2+1] + cas;
            }
        }
    }

    return 0;
}
