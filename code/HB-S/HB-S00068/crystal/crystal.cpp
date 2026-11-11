#include <bits/stdc++.h>
using namespace std;
const int N=500010;
using ll=long long;
int n;
ll m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d",ans);
    return 0;
}