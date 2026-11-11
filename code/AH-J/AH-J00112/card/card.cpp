#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],z;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            for(long long w=i;w<j;w++){
                if(a[j]==a[w]) z=j;
            }
        }
        for(long long t=z;t<=n;t++){
            s[a[t]]++;
        }
    }
    for(long long i=1;i<=m;i++){
        printf("%lld ",s[i]);
    }
    return 0;
}
