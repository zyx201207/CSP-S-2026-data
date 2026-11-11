#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const int maxn=505,maxm=5e5+5,maxq=1e5+5;
int c,n,m,d,q;
int w[maxm],k[maxn];
struct node{
    int id,t;
};
vector<node> ns[maxm];
pair<int,int> qst[maxq];
ll dis[maxn][maxn];
void flowed(){
    for(int t=1;t<=n;t++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][t]+dis[t][j]);
            }
        }
    }
}

int main()
{
    freopen("./subway.in","r",stdin);
    freopen("./subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,a,t;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            ns[a].push_back({i,t});
        }
    }
    for(int i=1;i<=q;i++){
        cin>>qst[i].first>>qst[i].second;
    }
    memset(dis,0x3f,sizeof dis);
    for(int t=1,l;t<=m;t++){
        l=ns[t].size();
        const vector<node>& v=ns[t];
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                int id1=v[i].id,id2=v[j].id;
                dis[id1][id2]=min(dis[id1][id2],ll(v[i].t+v[j].t));
                dis[id2][id1]=min(dis[id2][id1],ll(v[i].t+v[j].t));
            }
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    flowed();
    for(int t=1;t<=q;t++){
        ll ans=LLONG_MAX;
        int st=qst[t].first,ed=qst[t].second;
        const vector<node>& v1=ns[st],v2=ns[ed];
        int l1=v1.size(),l2=v2.size();
        for(int i=0;i<l1;i++){
            int id1=v1[i].id,t1=v1[i].t;
            for(int j=0;j<l2;j++){
                int id2=v2[j].id,t2=v2[j].t;
                ans=min(ans,t1+t2+dis[id1][id2]);
            }
        }
        cout<<ans+w[st]+w[ed]<<"\n";
    }
    return 0;
}

