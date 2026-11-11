#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
struct mp{
    int a,nt,metro;
    long long t;
}; //my pair
vector<mp>v[505],a[500005];
int k[505];
vector<int>wa[500005];
bool vis[500005],visk[505],flag=0;
long long fun(int x,int y,int nt){ //now end nowtrain
    if(x==y){
        flag=1;
        return (nt?v[nt][wa[x][nt]].t:0);
    }
    vis[x]=1;
    long long minn=-1;
    for(auto i:a[x]){
        long long o=-1;
        if(!vis[i.a]&&!visk[i.metro]){visk[i.metro]=1;o=fun(x,y,i.metro);visk[i.metro]=0;}
        if(minn==-1)minn=o;
        else if(o!=-1) minn=min(minn,o+(nt?v[nt][wa[x][nt]].t:0)+v[i.a][wa[x][i.a]].t);
    }
    vis[x]=0;
    return minn;
}
int main(){
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
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int fst,snd;
            cin>>fst>>snd;
            mp fs; //fst stnd
            fs.a=fst;
            fs.t=snd;
            v[i].push_back(fs);
            wa[fst].push_back(j);
        }
        for(int j=0;j<v[i].size();j++){
            for(int ii=0;ii<j;ii++){ //k bei4 zhan4 yong4 le
                mp mp1;
                mp1.a=v[i][j].a;
                mp1.t=0;
                mp1.nt=v[i][j].t;
                mp1.metro=i;
                a[v[i][ii].a].push_back(mp1);
                mp1.a=v[i][ii].a;
                mp1.nt=v[i][ii].t;
                a[v[i][j].a].push_back(mp1);
            }
        }
    }
    while(q--){
        int x,y;
        flag=0;
        memset(vis,0,sizeof vis);
        cin>>x>>y;
        cout<<w[x]+w[y]+fun(x,y,0)<<endl;
    }
    return 0;
}
