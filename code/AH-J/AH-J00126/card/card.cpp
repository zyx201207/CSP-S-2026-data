#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt[300005],h[500005],hcnt[300005],last[500005];
vector<vector<ll> > unb;
int main(void){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m,i,j;
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;++i)
        scanf("%lld",&h[i]);
    reverse(h+1,h+n+1);
    fill(last+1,last+m+1,n+1);
    unb=vector<vector<ll> >(m+1,vector<ll>(m+1,0));
    for(i=1;i<=n;++i){
        if(hcnt[h[i]]==0){
            hcnt[h[i]]=1,last[h[i]]=i;
        } else {
            for(j=i-1;j>last[h[i]];--j)unb[h[i]][h[j]]=(h[j]!=h[i]&&unb[h[j]][h[i]]==0?1:0);
            for(j=1;j<=m;++j)
                if(unb[h[i]][j])hcnt[j]=0;
        }
        for(j=1;j<=m;++j)cnt[j]+=hcnt[j];
    }
    for(i=1;i<=m;++i)
        printf("%lld ",cnt[i]);
	return 0;
}
