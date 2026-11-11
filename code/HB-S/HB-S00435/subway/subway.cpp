#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500,M=4000,INF=1e12;
ll trash,ln,stn,lnPstn,qst,gh[N*2+M+5][N*2+M+5],val,stnPln,stnIln,From,To,vis[N*2+M+5];pair<ll,ll>cur;queue<pair<ll,ll>>path;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&trash,&ln,&stn,&lnPstn,&qst);
    for(ll i=1;i<=2*stn+ln;i++)for(int j=1;j<=2*stn+ln;j++)gh[i][j]=INF;
    for(ll i=1;i<=2*stn+ln;i++)gh[i][i]=0;
    for(ll i=1;i<=stn;i++){
        scanf("%lld",&val);
        gh[i][i+stn]=gh[i+stn][i]=val;
    }for(ll i=2*stn+1;i<=2*stn+ln;i++){
        scanf("%lld",&stnPln);
        for(ll j=0;j<stnPln;j++){
            scanf("%lld%lld",&stnIln,&val);
            gh[i][stnIln+stn]=gh[stnIln+stn][i]=val;
        }
    }for(ll k=1;k<=2*stn+ln;k++)for(ll i=1;i<=2*stn+ln;i++)for(int j=1;j<=2*stn+ln;j++)gh[i][j]=min(gh[i][j],gh[i][k]+gh[k][j]);
    while(qst--){
        scanf("%lld%lld",&From,&To);
        printf("%lld\n",gh[From][To]);
    }return 0;
}
