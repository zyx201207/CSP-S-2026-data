#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,m,s[500010],ans;
inline long long find(int x){
    long long l=1,r=x,best=-1;
    while(l<=r){
        long long mid=(l+r)>>1;
        if((x-mid+1)*a[x]-(s[x]-s[mid-1])<=m){
            best=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return best;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        long long l=find(i);
        if(l!=-1)ans=max(ans,i-l+1);
    }
    printf("%lld",ans);
    return 0;
}
