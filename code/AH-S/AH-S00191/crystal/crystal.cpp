#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long l=1,r=0,ans=0;
    while(r<n){
        r++;
        ans+=(r-l)*(a[r]-a[r-1]);
        if(ans<=m) maxn=max(maxn,r-l+1);
        while(ans>m){
            ans-=a[r]-a[l];
            l++;
        }
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
