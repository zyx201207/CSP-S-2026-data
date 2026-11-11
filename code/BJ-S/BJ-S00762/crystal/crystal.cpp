#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,ans;
ll m;
ll a[N];
ll s[N];
bool CHECK(int x){
    for(int i=x;i<=n;i++){
        // x* target <=m+(s[i]-s[i-x])
        // target >=a[i] --> target=a[i]
        if(1LL*x*a[i]<=m+(s[i]-s[i-x])) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i]; // s[0]=0
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(CHECK(mid+1)) l=mid+1;
        else r=mid;
    }
    ans=l;
    printf("%d\n",ans);
    return 0;
}