#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+100;
int n,m;
int arr[MAXN];
signed main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
    }
    sort(arr+1,arr+n+1);
//    for(int i=1;i<=n;i++){
//        printf("%lld ",arr[i]);
//    }
//    printf("\n");
    int l=1,r=1;
    int sum=0;
    int ans=0;
    while(r<=n){
        sum+=(arr[r+1]-arr[r])*(r-l+1);
        ++r;
        while(sum>m&&l<r){
            sum-=arr[r]-arr[l];
            ++l;
 //           printf("*");
        }
        if(sum<=m){
            ans=max(ans,r-l+1);
        }
    }
    printf("%lld\n",ans);
    //?!Hollow Knight Crystal Peak?!

    return 0;
}
