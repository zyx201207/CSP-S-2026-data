#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,typ,ans,a[2000005];
int mindis(int x,int y){
    int nowpos=a[x],res=0;
    for(int i=x+1;i<y;++i){
        if(nowpos+d>=a[i]&&nowpos+d<a[i+1]){
            ++res;
            nowpos=a[i];
        }
    }
    if(nowpos+d>=a[y]) ++res;
    else return 0;
    return res;
}
void dfs(int x,int tgt,int stp,int lim){
    if(stp==lim||x==tgt){
        if(stp==lim&&x==tgt) ++typ;
        return ;
    } 
    int nowpos=a[x];
    for(int i=x;i<=tgt;++i){
        if(nowpos+d<a[i]) break;
        dfs(i,tgt,stp+1,lim);
    }
    return ;
}
bool solve(int x,int y){
    // cerr<<"in function solve(): trying to pair(x,y): "<<x<<" "<<y<<"\n";
    int discor=y-x+1,dis=mindis(x,y);
    if(dis==0) return 0;
    // cerr<<"back to solve(): find min dis: "<<dis<<"\n";
    typ=0;
    dfs(x,y,0,dis);
    // cerr<<"type: "<<typ<<"\n";
    if(typ==2) return 1;
    else return 0;
}
signed main(){
    // IAKIOI
    // 8 pts!! 
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d,ans=0;
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int u=1;u<=n;++u){
            for(int v=u+1;v<=n;++v){
                // cerr<<"in function main(): \n";
                // cerr<<"search points(u,v): "<<u<<","<<v<<"\n";
                if(solve(u,v)) ++ans;/*,cerr<<"back to main(): correct.\n";*/
                // else cerr<<"incorrect.\n";
            }
        }
        cout<<ans<<"\n";
    }
    cout.flush();
    return 0;
}