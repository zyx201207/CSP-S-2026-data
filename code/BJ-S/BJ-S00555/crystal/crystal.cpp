#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans=0;
bool flag=true;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        if((a[i]-a[i-1])!=(a[i-1]-a[i-2])) flag=false;
    }
    if(flag && n>=3){
        int d=a[2]-a[1];
        for(int i=2;i<=n;i++){
            if(1LL*i*(i-1)/2*d>m){
                ans=i-1;
                break;
            }
        }
        if(1LL*n*(n-1)/2*d<=m) ans=n;
    }
    else{
        for(int i=2;i<=n;i++){
            int new_m=m;
            for(int j=i-1;j>=1;j--){
                if(a[i]>a[j]) new_m-=(a[i]-a[j]);
                if(new_m>=0 && j==1) ans=max(ans,i);
                if(new_m<0){
                    ans=max(ans,i-j);
                    break;
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
