#include<bits/stdc++.h>
using namespace std;
struct awa{
    int ai,ti,nxt;
};
int c,n,m,d,q,l,r,w[500005],vis[500005],x[5005][505];
long long ans;
awa qry[100005];
vector<awa>stat[500005];
void dfs(int u,int num,int enr,long long s){ //u当前站点，num当前路线，s当前代价和
    if(s>=ans)return ;
    if(u==r){
        ans=min(ans,s+x[r][enr]);
        return ;
    }
    for(awa v : stat[u]){
        if(!v.nxt)continue;
        if(vis[v.nxt])continue;
        vis[v.nxt]=1;
        if(v.nxt==r)enr=v.ai;
        if(v.ai==num)dfs(v.nxt,v.ai,enr,s);
    	else dfs(v.nxt,v.ai,enr,s+x[u][num]+v.ti);
    	vis[v.nxt]=0;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int ki;
        cin>>ki;
        int lsta=0,lstt=0;
        for(int j=1;j<=ki;j++){
            int ai,ti;
            cin>>ai>>ti;
            if(j>1)stat[lsta].push_back({i,lstt,ai});
            if(1<=c&&c<=6)x[ai][i]=ti;
            lsta=ai; lstt=ti;
        }
        stat[lsta].push_back({i,lstt,0});
    }
    for(int i=1;i<=q;i++)cin>>qry[i].ai>>qry[i].ti;
    if(1<=c&&c<=6){ //数据小打暴力
        for(int i=1;i<=q;i++){
            l=qry[i].ai,r=qry[i].ti;
            if(l==r){
                cout<<'0\n';
                continue;
            }
            ans=1e18;
            dfs(l,0,0,w[l]+w[r]);
            cout<<ans<<endl;
        }
    }
    return 0;
}
