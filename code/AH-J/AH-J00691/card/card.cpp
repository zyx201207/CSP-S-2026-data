#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10,M=3e5+10;
LL n,m,a[N],cnt[M],t[N],ans[M],vis[N],cnt2[M],l[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        t[i]=a[i];
        cnt[a[i]]++;
    }
    sort(t+1,t+n+1);
    for(LL ti=1;ti<=n;ti++){
        memset(cnt2,0,sizeof cnt2);
        memset(vis,0,sizeof vis);
        for(LL i=ti;i<=n;i++){
            LL x=a[i];
            cnt2[x]++;
            if(cnt2[x]==1) l[x]=i;
            if(cnt[x]>=2&&cnt2[x]==2){
                    for(LL j=l[x];j<i;j++){
                    vis[j]=1;
                    cnt2[a[j]]=0;
                }
                cnt2[x]=1;
            }
        }
        //for(LL i=1;i<ti;i++) cout<<"  ";
        for(LL i=ti;i<=n;i++){
            //cout<<vis[i]<<' ';
            if(vis[i]==0) ans[a[i]]++;
        }
        //cout<<endl;
        cnt[a[ti]]--;
    }
    for(LL i=1;i<=m;i++) printf("%lld ",ans[i]);
    return 0;
}
