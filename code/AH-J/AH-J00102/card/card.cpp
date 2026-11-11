#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10,M=3e5+10;
LL n,m,a[N],cnt[M],pre[M],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(LL i=1;i<=n;i++){
        memset(cnt,0,sizeof cnt);
        memset(pre,0,sizeof pre);
        for(LL j=i;j<=n;j++){
            if(!cnt[a[j]]) cnt[a[j]]++,pre[a[j]]=j;
            else{
                for(LL k=pre[a[j]];k<j;k++){
                    if(cnt[a[k]]!=0) cnt[a[k]]--;
                }
                cnt[a[j]]=1,pre[a[j]]=j;
            }
        }
        for(LL j=1;j<=m;j++){
            if(cnt[j]) ans[j]++;
        }
    }
    for(LL i=1;i<=m;i++) printf("%lld ",ans[i]);
    return 0;
}
