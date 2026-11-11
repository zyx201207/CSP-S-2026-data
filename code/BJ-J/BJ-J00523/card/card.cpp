#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[300005],c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(long long i=1;i<=n;i++){
        int t=1;
        for(long long j=i;j<=n;j++){
            b[t]=a[j];
            for(int k=t-1;k>0;k--){
                if(b[k]==a[j]){
                    t=k;
                }
            }
            t++;
        }
        for(long long j=1;j<t;j++){
            c[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
