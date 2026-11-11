#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int c,t;
ll n,d,x[N],ans,dp[N],pos[N];
ll read(){
    ll x=0*1ll,f=1ll;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10*1ll+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void solve(){
    n=read(),d=read();
    ans=0;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        x[i]=read();
        pos[i]=lower_bound(x+1,x+i+1,x[i]-d)-x;
        if(i-pos[i]>2)continue;
        if(i-pos[i]==1){
            dp[i]=dp[pos[i]]+1;
            continue;
        }else if(i-pos[i]==2){
            int id1=pos[i],id2=pos[i]+1;
            int p1=pos[id1],p2=pos[id2];
            if(id1-p1<1||id2-p2<1)continue;
            if(id2-p2==1)ans+=dp[id2];
            else ans++;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();t=read();
    while(t--){
        solve();
    }
}
