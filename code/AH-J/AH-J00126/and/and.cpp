#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll B2[200005][35];
ll ans[35],h[200005],mx=0,cnt[35];
unordered_set<ll> st;
void solB2(ll x,ll t){
    ll i=1;
    while(x!=0){
        if(x&1)B2[t][i]=1,cnt[i]++;
        else B2[t][i]=0;
        x>>=1,++i;
    }
    mx=max(mx,i-1);
    return;
}
int main(void){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ll n,i,j,res=0,m,s;
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;++i)scanf("%lld",&h[i]),st.insert(i);
    sort(h+1,h+n+1,greater<ll>());
    for(i=1;i<=n;++i)
        solB2(h[i],i);
//  for(i=1;i<=n;++i){
//      for(j=mx;j>=1;--j)
//          printf("%lld",B2[i][j]);
//      printf("\n");
//  }
    for(i=mx;i>0;--i){
        ll ct=0;
        for(j=1;j<=n;++j){
            if(st.count(j)&&B2[j][i])ct++;
            if(ct>=m)break;
        }
        if(ct<m)continue;
        ans[i]=1;
        for(j=1;j<=n;++j)
            if(st.count(j)&&B2[j][i]==0)
                st.erase(j);
    }
    for(i=1,s=1;i<=mx;++i)
        res+=s*ans[i],s<<=1;
    printf("%lld",res);
	return 0;
}
