#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,m,n,d,q,w[100005],dis[500005],a[550000],t[550000];
struct edge{
    int u;
    int l;
    int t;
};
vector<edge> e[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int k1=1;k1<=k;k1++){
            for(int k2=1;k2<=k;k2++){
                edge tmp;
                tmp.u=a[k1],tmp.l=i,tmp.t=t[a[k1]]+t[a[k2]];
                e[k2].push_back(tmp);
                tmp.u=a[k2];
                e[k1].push_back(tmp);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x,y;
        memset(dis,0x3f,sizeof(dis));
        priority_queue<pair<int,int>> q;
        q.push({0,x});
        while(!q.empty()){
            int tmp=q.top().second;q.pop();
            for(int j=0;j<e[tmp].size();j++){
                if(dis[e[tmp][j].u]>dis[tmp]+e[tmp][j].t){
                    dis[e[tmp][j].u]=dis[tmp]+e[tmp][j].t;
                    q.push({-dis[e[tmp][j].u],e[tmp][j].u});
                }
            }
        }
        cout<<dis[y]<<'\n';
    }
    return 0;
}
