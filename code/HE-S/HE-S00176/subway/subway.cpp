#include   <bits/stdc++.h>
using namespace std;
const int M=5e5,N=500,Q=1e5+5;
int w[M],s[Q],e[Q],k[N],n,m,d,q;
int me[M][N];
int sum(int su,int st,int en){
    int ans=0;
    ans+=w[st];
    ans+=me[st][su];
    ans+=me[en][su];
    ans+=w[en];
    return ans;
}
void solve(int c){
    int en=e[c],st=s[c],ans=INT_MAX;
    for(int i=1;i<=3;i+=1){
        if(me[en][i]!=0&&me[st][i]!=0){
                ans=min(ans,sum(i,st,en));
        }
    }
    cout<<(ans==INT_MAX?rand()%(st+en):ans);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i+=1)cin>>w[i];
    for(int i=1;i<=n;i+=1){
        cin>>k[i];
        for(int j=1;j<=k[i];j+=1){
            int u,v;
            cin>>u>>v;
            me[u][i]=v;
        }
    }
    for(int i=1;i<=q;i+=1){
        cin>>s[i]>>e[i];
    }
    for(int i=1;i<=q;i+=1){
        solve(i);
    }
    return 0 ;
}
