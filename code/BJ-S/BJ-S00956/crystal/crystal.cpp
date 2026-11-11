#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10;
LL a[N],s[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
    //for(int i=1;i<=n;i++) printf("%d ",s[i]);
    printf("\n");
    for(LL l=1,r=1;r<=n && l<=n;){
        //s[r]-s[l]-(l-1)*(a[r]-a[l])
        if(s[r+1]-s[l]-(l-1)*(a[r+1]-a[l])<=m){
            r++;
        }
        else {
            ans=max(r-l+1ll,ans);
            //printf("%d %d %d\n",l,r,ans);
            l++;
        }
    }
    printf("%lld",ans);
    return 0;
}
