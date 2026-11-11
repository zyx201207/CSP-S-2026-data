#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll c,n,m,p,q,w[N],k,a,t,x,y,l[N],d[21][N],dp[505][505];
int id[21][N];
int rd(){
    char ch=getchar();int x=0;
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=rd();n=rd();m=rd();p=rd();q=rd();
    for(ll i=1;i<=m;i++) w[i]=rd();
    for(ll i=1;i<=n;i++){
        k=rd();
        while(k--){
            a=rd();t=rd();l[a]++;
            d[l[a]][a]=t;id[l[a]][a]=i;
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(ll i=1;i<=n;i++) dp[i][i]=0;
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=l[i];j++){
            for(ll g=1;g<=l[i];g++){
                dp[id[j][i]][id[g][i]]=min(dp[id[j][i]][id[g][i]],d[j][i]+d[g][i]);
                dp[id[g][i]][id[j][i]]=min(dp[id[g][i]][id[j][i]],d[j][i]+d[g][i]);
            }
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--){
        x=rd();y=rd();ll ans=1e18;
        for(ll i=1;i<=l[x];i++){
            for(ll j=1;j<=l[y];j++){
                ans=min(ans,w[x]+w[y]+d[i][x]+d[j][y]+dp[id[i][x]][id[j][y]]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
