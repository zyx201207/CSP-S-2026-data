#include<bits/stdc++.h>
using namespace std;
long long w[600],k[600],a[600][10],v[600];
long long c,n,m,d,q,st,ed,t,mint=0x3f3f3f3f;
/*void bfs(long long nows,long long nowt){
    if(nows==ed){
        mint=min(nowt,mint);
        return;
    }
    nowt+=t;
    if(v[nows]==1)return;

    v[nows]=1;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            if(a[i][j]!=0){
                bfs(a[i][j]*1LL,nowt+t);
            }
        }
    }
    v[nows]=0;
    return;
}*/
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;

    for(long long i=1;i<=m;i++)cin>>w[i];
    for(long long i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t;
        }
    }
    while(q--){
        memset(v,0,sizeof(v));
        mint=0x3f3f3f3f;
        cin>>st>>ed;
        cout<<w[st]+w[ed]+2*t*(abs(ed-st)+1)<<"\n";
    }

}
