#include<bits/stdc++.h>
using namespace std;
const int N=500+10,M=500000+10;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],start,ending,vis[N],minm,ans,quick[N][N];
vector<int> b[M];
void dfs(int x,int number,int value,int ok) {
    if(x==ending) {
        minm=min(minm,value+t[number][ending]);
        return;
    }
    if(value>minm) return;
    if(vis[number]==0) vis[number]=value;
    if(vis[number]<value&&t[number][x]==0) return;
    vis[number]=min(vis[number],value);
    if(ok==0) {
        for(int i=1;i<=k[number];i++) {
            if(a[number][i]==x) continue;
            dfs(a[number][i],number,value,1);
        }
    }
    for(int i=0;i<b[x].size();i++) {
        int num=b[x][i];
        if(num==number) continue;
        if(quick[number][num]<t[number][x]+t[num][x]) return;
        quick[number][num]=quick[num][number]=t[number][x]+t[num][x];
        dfs(x,num,value+t[number][x]+t[num][x],0);
    }
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++) {
        cin>>k[i];
        for(int j=1;j<=k[i];j++) {
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
            b[a[i][j]].push_back(i);
        }
    }
    memset(quick,0x3f,sizeof(quick));
    while(q--) {
        cin>>start>>ending;
        ans=0x7fffffff;
        for(int i=0;i<b[start].size();i++){
            minm=0x7fffffff;
            dfs(start,b[start][i],0,0);
            ans=min(ans,minm+w[start]+w[ending]+t[b[start][i]][start]);
            memset(vis,0,sizeof(vis));
        }
        cout<<ans<<endl;
    }
    return 0;
}
