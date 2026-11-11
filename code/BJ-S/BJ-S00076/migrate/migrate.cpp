#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e6+10;
const ll maxm=1e16+10;
ll c,t,n,x[maxn],len,d,f[maxn],s[maxn],cnt[maxn],ans;
vector <ll> p;
void fillin(){
    ll tmp=1;
    for(ll i=1;i<=n;i++){
        while(tmp+1<=n&&x[tmp+1]-x[i]<=d)
            tmp++;
        f[i]=tmp;
    }
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld %lld",&c,&t);
    while(t--){
        scanf("%lld %lld",&n,&d);
        for(ll i=1;i<=n;i++){
            scanf("%lld",x+i);
        }
        fillin();
        ans=0;
        for(ll i=1;i<=n;i++){
            for(ll j=i;j<=n;j++)
                cnt[j]=0,s[j]=maxn;
            cnt[i]=1;s[i]=0;
            for(ll j=i;j<=n;j++){
                for(ll k=j+1;k<=f[j];k++){
                    if(s[k]>s[j]+1)
                        s[k]=s[j]+1,cnt[k]=cnt[j];
                    else if(s[k]==s[j]+1)
                        cnt[k]+=cnt[j];
                }
                if(cnt[j]==2)
                    ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
