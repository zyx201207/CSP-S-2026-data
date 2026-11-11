#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
    int u,v;
};
vector<edge> a;
vector<int> e[6000];
bool cmp(edge x,edge y){
    if(x.v==y.v) return x.u<y.u;
    return x.v<y.v;
}
int c,t,n,d,x[3000000],visit[10000],path,mmin=1e14,st[6000][6000],cnt;
void dfs(int x,int y,int op){
    if(x==y){
        mmin=min(mmin,path);
        if(op!=0) path-=(op+1);
        return;
    }
    for(int i=0;i<e[x].size();i++){
        if(visit[e[x][i]]) continue;
        path++;
        visit[e[x][i]]=1;
        dfs(e[x][i],y,0);
        path--;
        visit[e[x][i]]=0;
    }
}
void last(int start,int en,int x,int y,int step){
    if(step==st[start][en]){
        if(x==y) cnt++;
        return;
    }
    for(int i=0;i<e[x].size();i++){
        if(visit[e[x][i]]) continue;
        step++;
        visit[e[x][i]]=1;
        last(start,en,e[x][i],y,step);
        step--;
        visit[e[x][i]]=0;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
            for(int i=1;i<=n-1;i++){
                for(int j=i+1;j<=n;j++){
                    if(x[j]-x[i]<=d){
                        a.push_back({i,j});
                        st[i][j]=1;
                    }
                }
            }
            sort(a.begin(),a.end(),cmp);
            //for(int i=0;i<a.size();i++) cout<<a[i].u<<a[i].v<<" ";
            for(int i=0;i<a.size();i++){
                e[a[i].u].push_back(a[i].v);
            }
            /*for(int i=1;i<=4;i++){
                for(int j=0;j<e[i].size();j++){
                    cout<<e[i][j]<<" ";
                }
                cout<<endl;
            }*/
            for(int i=1;i<=n-1;i++){
                for(int j=i+1;j<=n;j++){
                    dfs(i,j,0);
                    st[i][j]=mmin;
                    mmin=1e14;
                }
            }
            /*for(int i=1;i<=n-1;i++){
                for(int j=i+1;j<=n;j++) cout<<st[i][j]<<" ";
                cout<<endl;
            }*/
            int total_ans=0;
            for(int i=1;i<=n-1;i++){
                for(int j=i+1;j<=n;j++){
                    cnt=0;
                    last(i,j,i,j,0);
                    //if(cnt==2) cout<<i<<" "<<j<<endl;
                    if(cnt==2) total_ans++;
                }
            }
            cout<<total_ans<<endl;
            a.clear();
            for(int i=1;i<=n;i++) e[i].clear();
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    st[i][j]=0;
                }
            }
    }
    return 0;
}
