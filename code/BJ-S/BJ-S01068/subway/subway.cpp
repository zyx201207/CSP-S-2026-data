#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,dd,q,w[500005],to[500005],len[500005];
ll dis[505][505];
vector<ll> a[5005],t[5005];
struct d{
    int v,w;
};
vector<d> cnt[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>dd>>q;
    //cout<<n<<" "<<m<<" "<<dd<<" "<<q<<endl;
    for(int i=1;i<=m;i++) cin>>w[i];
    //cout<<endl;
    for(int i=1;i<=n;i++){
        ll k;cin>>k;
        //cout<<k<<endl;
        for(int j=1;j<=k;j++){
            ll a1,t1;cin>>a1>>t1;
            //cout<<a1<<" "<<t1<<" ";
            cnt[a1].push_back({i,t1});
            a[i].push_back(a1);
            t[i].push_back(t1);
        }
        //cout<<endl;
    }
    /*
    for(int i=1;i<=n;i++){
        //cout<<a[i].size()<<" ";
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vector<ll> st;
            for(int k=0;k<a[i].size();k++){
                ll u=a[i][k];
                st.push_back(u);
                to[u]++;
                len[u]+=t[i][k];
                //cout<<u<<" ";
            }
            //cout<<endl;
            for(int k=0;k<a[j].size();k++){
                ll u=a[j][k];
                st.push_back(u);
                to[u]++;
                len[u]+=t[j][k];
                if(to[u]==2){
                    //cout<<u<<" ";
                    //cout<<i<<" "<<j<<" "<<len[u]<<" "<<u<<endl;
                    dis[i][j]=min(dis[i][j],(ll)len[u]);
                    dis[j][i]=min(dis[j][i],(ll)len[u]);
                }
                //cout<<u<<" ";
            }
            //cout<<endl;
            for(int k=0;k<st.size();k++) to[st[k]]=len[st[k]]=0;
        }
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    while(q--){
        ll x,y,ans=3e18;
        cin>>x>>y;
        for(int i=0;i<cnt[x].size();i++){
            ll u=cnt[x][i].v,w1=cnt[x][i].w;
            for(int j=0;j<cnt[y].size();j++){
                ll v=cnt[y][j].v,w2=cnt[y][j].w;
                //cout<<u<<" "<<v<<" "<<dis[u][v]<<" "<<w1<<" "<<w2<<endl;
                ans=min(ans,dis[u][v]+w1+w2);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
