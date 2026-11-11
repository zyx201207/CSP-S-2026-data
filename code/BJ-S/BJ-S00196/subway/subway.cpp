#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
typedef pair<int,int> PII;
int n,m,d,q,c,w[N],dis[1005][N];
vector<PII> v[N];
vector<PII> a[505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            a[i].push_back({x,y});
            for(int p=0;p<j-1;p++){
                int l=a[i][p].first,r=a[i][p].second;
                v[x].push_back({l,r+y});
                v[l].push_back({x,r+y});
                //cout<<x<<" "<<l<<" "<<r+y<<endl;
            }
        }
    }
    while(q--){
        int s,f;
        cin>>s>>f;
        priority_queue< PII , vector<PII>, greater<PII> > q;
        if(dis[s][0]==1){
            cout<<dis[s][f]+w[s]+w[f]<<"\n";
            continue;
        }
        else if(dis[f][0]==1){
            cout<<dis[f][s]+w[s]+w[f]<<"\n";
            continue;
        }
        dis[s][0]=1;
        dis[s][s]=0;
        q.push({dis[s][s],s});
        while(q.size()){
            auto T=q.top();q.pop();
            int d=T.first,u=T.second;
            if(dis[s][u]!=d) continue;
            //cout<<u<<" "<<d<<endl;
            for(auto K:v[u]){
                int x=K.first,w=K.second;
                if(dis[s][x]>dis[s][u]+w){
                    dis[s][x]=dis[s][u]+w;
                    q.push({dis[s][x],x});
                    //cout<<x<<" "<<dis[x]<<endl;
                }
            }
        }
        cout<<dis[s][f]+w[s]+w[f]<<"\n";
    }
    return 0;
}
