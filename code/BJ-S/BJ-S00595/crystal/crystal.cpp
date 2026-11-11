#include<bits/stdc++.h>
using namespace std;
int n,ans,nw;
long long a[500005],sum,q[500005],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    ans=1;
    for(int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]*(i-1)-q[i-1]>m){
            nw=i-1;
            break;
        }
    }
    if(nw==0){
        printf("%d",n);
        return 0;
    }
    ans=max(ans,nw);
    for(int i=nw+1,l=1;i<=n;i++){
        while(l<i&&a[i]*(i-l)-(q[i-1]-q[l-1])>m){
            l++;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d",ans);
    return 0;
}