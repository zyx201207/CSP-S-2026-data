#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
using LL =long long;
const LL N = 5e5+5;

LL n,m,ans,maxn,a[N],cnt[N],cntans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(LL i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(LL i=1;i<=n;i++){
        vector<LL> v;
        memset(cnt,0,sizeof cnt);
        for(LL j=i;j<=n;j++){
            v.push_back(a[j]);
            cnt[a[j]]++;
            int pos;
            for(LL k=0;k<v.size()-1;k++){
                if(v[k]==-1)continue;
                if(v[k]==a[j])v[k]=-1,pos=k;
                if(k>=pos)v[k]=-1,cnt[v[k]]--;
            }
        }
        for(LL j=1;j<=m;j++)
            if(cnt[j])cntans[j]++;
    }
    for(LL i=1;i<=m;i++)printf("%lld ",cntans[i]);
    return 0;
}
