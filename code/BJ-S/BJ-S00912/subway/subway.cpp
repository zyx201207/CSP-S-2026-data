#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int maxn=5e5+13,maxm=513;
int w[maxn];
int ans[maxm][maxm];
int qz[maxm],flag[maxm];
struct node{
    int to,dis;
};
vector<node>g[maxm];//地铁线路的连边
vector<node>f[maxn];//地铁站处的连边
void dj(int s){
    int now=0,cnt=0;
    memset(qz,0x3f,sizeof(qz));
    memset(flag,0,sizeof(flag));
    now=s;
    qz[s]=0;
    while(cnt<n){
        cnt++;
        flag[now]=1;
        ans[s][now]=qz[now];
        for(auto e:g[now]){
            int mb=e.to,dis=e.dis;
            //cout<<qz[mb]<<"*";
            qz[mb]=min(qz[mb],qz[now]+dis);
        }
       // cout<<now<<" ";
        int pos=0,minn=1000000000000000;
        for(int i=1;i<=n;i++){
            if(flag[i]) continue;
            if(qz[i]<minn){
                minn=qz[i];
                pos=i;
            }
        }
        now=pos;
    }
    //cout<<'\n';
    return;

}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            node c;
            int id,ti;
            cin>>id>>ti;
            c.to=i;
            c.dis=ti;
            f[id].push_back(c);
        }
    }
    for(int i=1;i<=m;i++){
        int siz=f[i].size();
       // cout<<siz<<" ";
       for(int j=0;j<siz;j++){
           for(int k=0;k<siz;k++){
               if(j==k) continue;
               node edge;
               edge.to=f[i][k].to;
               edge.dis=f[i][k].dis+f[i][j].dis;
               g[f[i][j].to].push_back(edge);
           }
       }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j].to<<" ";
        }
        cout<<'\n';
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j].dis<<" ";
        }
        cout<<'\n';
        cout<<'\n';
    }
    cout<<'\n'<<'\n';*/
    for(int i=1;i<=n;i++){
        dj(i);
       /* for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';*/
    }
    //cout<<'\n'<<'\n';
    while(q--){
        int l,r;
        cin>>l>>r;
        int minn=1000000000000000;
        for(int i=0;i<f[l].size();i++){
            for(int j=0;j<f[r].size();j++){
                minn=min(minn,f[l][i].dis+f[r][j].dis+ans[f[l][i].to][f[r][j].to]);
            }
        }
        cout<<minn+w[l]+w[r]<<'\n';
    }
    return 0;

}
