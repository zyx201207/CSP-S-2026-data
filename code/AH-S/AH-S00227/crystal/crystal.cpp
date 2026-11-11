#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum[500005];
bool cmp(long long x,long long y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=1,ans=0;
    long long k=0;
    while(l<=n){
        while(r<=n&&(r-l)*a[r]-(sum[r-1]-sum[l-1])<=m){
            k=(r-l)*a[r]-(sum[r-1]-sum[l-1]);
            r++;
        }
        ans=max(ans,r-l);
        k=a[r-1]-a[l];
        l++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
