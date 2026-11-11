#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,ans;
struct uct{
    LL sum;
    char ch;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i].sum);
        cin>>a[i].ch;
    }
    LL l=1,r=n,tmpl=0,tmpr=0;
    while(l<r){
        LL tmp=min(a[l].sum-tmpl,a[r].sum-tmpr);
        if(a[l].ch!=a[r].ch){
            ans+=tmp;
        }
        tmpl+=tmp;
        tmpr+=tmp;
        if(tmpl==a[l].sum){
            l++;
            tmpl=0;
        }
        if(tmpr==a[r].sum){
            r--;
            tmpr=0;
        }
    }
    printf("%lld",ans);
    return 0;
}
