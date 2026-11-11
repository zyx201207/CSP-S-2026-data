#include<bits/stdc++.h>
using namespace std;
long long ans;
int go[200003],will_line[200002],ct[500002],gopoint=1,let=1;
bool vis[500002];int c,n,m,d,q,k,w[500002];
int t[10001][102],a[10001][102];
bool l[10001][102];int nst[200003];
void reset(){
    ans=(long long)INT_MAX*(long long)INT_MAX;
    gopoint=1;
    let=1;
    memset(vis,false,sizeof(vis));
    memset(ct,INT_MAX,sizeof(ct));
    memset(go,0,sizeof(go));
    memset(will_line,0,sizeof(will_line));
    memset(nst,0,sizeof(nst));
}
static void bfs(int nowp,int f,int ti,int line){
    if(nowp==f){
        ans=min(ans,(long long)t);
        return;
    }
    vis[nowp]=true;
    ct[nowp]=min(ct[nowp],ti);
    //now sum time
    for(int i=1;i<=n;i++){
        if(l[nowp][i]){
            for(int j=1;j<=d;j++){
                if(!vis[a[i][j]]){
                go[gopoint++]=a[i][j];
                will_line[gopoint]=i;
                }//''
            }if(line!=i){
                nst[gopoint]+=t[nowp][i]+ti;}
        }
    }
    bfs(go[let++],f,nst[let],will_line[let]);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    memset(l,false,sizeof(l));
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=2*k;j++){
            cin>>a[i][j]>>t[i][j];
            l[a[i][j]][i]=1;
        }
    }
    int s,e;
    for(int i=1;i<=n;i++){
        cin>>s>>e;
        reset();
        bfs(s,e,w[s]+w[e],0);
        cout<<ans<<endl;
    }
    return 0;
}
