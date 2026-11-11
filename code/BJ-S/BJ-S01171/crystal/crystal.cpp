#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,m;
const int N=500010;
ll a[N],d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    //for(int i=1;i<=n;i++){
    //    printf("%lld ",a[i]);
    //}
    //puts("");
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        d[i]=a[i+1]-a[i];
    }
    //for(int i=1;i<n;i++){
    //    printf("%lld ",d[i]);
    //}
    //puts("");
    int l=1,r=1,ans=0;
    ll sum=0;
    while(r<n){
        sum+=d[r]*(r-l+1);
        if(sum>m){
            ans=max(ans,r-l+1);
            //printf("l=%d r=%d sum=%lld ans=%d\n",l,r,sum,ans);
            while(sum>m){
                sum-=(a[r+1]-a[l]);
                l++;
            }
        }
        r++;
    }
    printf("%d",ans);
    return 0;
}
/*
5 5
1 2 4 8 9

6 5
1 2 4 7 8 9
1 2 3 1 1

1 5 3 5
1 2 3 4 5
*/
