#include<bits/stdc++.h>
using namespace std;
//t,w : long long
int c,n,m,d,q,a,k;
long long zw[600000],t;
struct st{
    int u,v;
    long long w;
    bool operator < (const st &x) const{
        return w > x.w;
    }
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>zw[i];
    }
    vector<st> e[m*d+100];
    for(int i=0;i<m*d+100;i++){
        e[i].push_back({i,i,0});
    }
    long long dis[m+1][m*d+100];
    bool fi[m*d+100];
    int cnt=m;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            cnt++;
            e[cnt].push_back({cnt,a,t});
            e[a].push_back({a,cnt,t});
            if(j>1){
                e[cnt].push_back({cnt,cnt-1,0});
                e[cnt-1].push_back({cnt-1,cnt,0});
            }
        }
    }

    for(int o=1;o<=q;o++){
        int s,en;
        cin>>s>>en;
        long long ans=zw[s]+zw[en];
        if(s==en){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<m*d+100;i++) fi[i]=0,dis[s][i]=100000000;
        dis[s][s]=0;
        priority_queue <st> q;
        q.push(e[s][0]);
        while(!q.empty()){
            st u=q.top();
            q.pop();
            int nu=u.u;
            if(fi[nu]==1) continue;
            fi[nu]=1;
            for(int i=1;i<e[nu].size();i++){
                int v=e[nu][i].v;
                long long w=e[nu][i].w;
                if(fi[v]==1) continue;
                if(dis[s][v]>dis[s][nu]+w){
                    dis[s][v]=dis[s][nu]+w;
                    q.push(e[v][i]);
                }
            }
        }
        cout<<ans+dis[s][en]<<endl;
    }
    return 0;
}
