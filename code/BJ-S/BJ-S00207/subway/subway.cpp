#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL M=6e5+5,N=5e2+5;
struct node{
    LL d,v;
    bool operator<(const node& aa)const{
        return v>aa.v;
    }
};
LL c,n,m,d,qq,w[M],ans[N][N],dis[M],tu2[N][N];
vector<node>tu[M],tu1[M];
priority_queue<node>q;
bool bj[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(LL i=1;i<=m;i++)cin>>w[i];
    for(LL i=1;i<=n;i++){
        LL k1;cin>>k1;
        for(LL j=1;j<=k1;j++){
            LL aa,bb;cin>>aa>>bb;
            tu[aa].push_back({i+m,bb});
            tu[i+m].push_back({aa,bb});
            tu1[aa].push_back({i+m,bb});
        }
    }
    for(LL i=1;i<=n;i++){
        for(LL j=1;j<=n;j++){
            tu2[i][j]=1e18;
        }
    }
    for(LL i=1;i<=m;i++){
        for(LL j=0;j<tu1[i].size();j++){
            node v1=tu1[i][j];
            for(LL k=0;k<tu1[i].size();k++){
                node v2=tu1[i][k];
                if(v1.d==v2.d)continue;
                if(v2.v+v1.v<tu2[v1.d-m][v2.d-m]){
                    tu2[v1.d-m][v2.d-m]=tu2[v2.d-m][v1.d-m]=v1.v+v2.v;
                }
            }
        }
    }
    for(LL k=1;k<=m;k++){
        while(!q.empty())q.pop();
        for(LL i=1;i<=n;i++){
            bj[i]=0;dis[i]=2e9;
        }dis[k]=0;
        q.push({k,0});
        while(!q.empty()){
            node u=q.top();q.pop();
            if(bj[u.d])continue;
            bj[u.d]=1;
            for(LL i=1;i<=n;i++){
                if(bj[i]||tu2[u.d][i]==1e18)continue;
                LL vv=tu2[u.d][i];
                if(dis[i]>u.v+vv){
                    dis[i]=u.v+vv;
                    q.push({i,dis[i]});
                }
            }
        }
        for(LL i=1;i<=n;i++){
            ans[k][i]=dis[i];
        }
    }
    for(LL i=1;i<=qq;i++){
        LL aa,bb,minn=1e18;cin>>aa>>bb;
        for(LL j=0;j<tu1[aa].size();j++){
            node v1=tu1[aa][j];
            for(LL k=0;k<tu1[bb].size();k++){
                node v2=tu1[bb][k];
                minn=min(minn,ans[v1.d-m][v2.d-m]+v1.v+v2.v);
            }
        }
        //cout<<minn<<'\n';
        cout<<minn+w[aa]+w[bb]<<'\n';
    }
    return 0;
}
