#include<bits/stdc++.h>
using namespace std;
const int MAXLEN=5e5+5;
#define int long long
int n,a[MAXLEN],m;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int l=1,r=1,ans=0,curw=0;
    for(;r<=n;r++){
        curw+=(r-l)*(a[r]-a[r-1]);
        while(curw>m){
            curw-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    printf("%lld",ans);
}
