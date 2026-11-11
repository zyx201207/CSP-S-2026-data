#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans=0,c=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    memset(b,0,sizeof(b));
    for (int i=1;i<=n;i++){
        b[i]=a[i]-a[1];
    }
    ans=b[1];
    c=1;
    for (int j=1;j<=n-1;j++){
        ans=0;
        for (int i=j;i<=n-1;i++){
            ans=ans+(i-j+1)*(b[i+1]-b[i]);
            if (ans>m){
                break;
            }
            c=max(c,(long long)(i+2-j));
        }
    }
    printf("%lld",c);
    return 0;
}
