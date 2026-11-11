#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
long long sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int ans=0;
    int l=1;
    for(int i=1;i<=n;i++){
        while((i-l+1ll)*a[i]-(sum[i]-sum[l-1])>m) l++;
        ans=max(ans,i-l+1);
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}