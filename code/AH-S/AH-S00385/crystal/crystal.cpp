#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N],ans;
bool check(int l,int r){
    return a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i,j=i;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid,i)){
                j=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-j+1);
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
6 3
-10000 1 1 1 1 1
ans:5


*/
