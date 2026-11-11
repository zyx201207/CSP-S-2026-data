#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],pre[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    int ans=0;
    for(int i=1,j=1;j<=n;i++){
        j=max(j,i);
        while(j+1<=n&&pre[j+1]-pre[i-1]+m>=1ll*(j-i+2)*a[j+1])
            j++;
        ans=max(ans,j-i+1);
    }
    printf("%d",ans);
    return 0;
}
