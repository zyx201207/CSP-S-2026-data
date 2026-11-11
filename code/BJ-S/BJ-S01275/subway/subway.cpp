#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int ds[505][505];
int w[500005],k[500005];
vector<int> a[500005],t[500005];
vector<int> ct[500005];
vector<int> ct2[500005];
vector<int> v[505],cc[505];
int solve(int l,int r){
    int dis[505]={0};
    int vis[505]={0};
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    for(int i=0;i<ct[l].size();i++){
        dis[ct[l][i]]=ct2[l][i];
        q.push(ct[l][i]);
        //vis[ct[l][i]]=1;
    }
    while(!q.empty()){
        int nx=q.front();q.pop();
        for(int i=0;i<v[nx].size();i++){
            if(dis[v[nx][i]]>dis[nx]+cc[nx][i]){
                dis[v[nx][i]]=dis[nx]+cc[nx][i];
                q.push(v[nx][i]);
            }
        }
    }
    int anss=9000000000000000000;
    for(int i=0;i<ct[r].size();i++)anss=min(anss,dis[ct[r][i]]+ct2[r][i]);
    return anss;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    memset(ds,0x3f,sizeof(ds));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;cin>>x>>y;
            a[i].push_back(x);t[i].push_back(y);
            ct[x].push_back(i);
            ct2[x].push_back(y);
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=0;j<ct[i].size();j++){
            for(int k=0;k<ct[i].size();k++){
                if(j==k)continue;
                ds[ct[i][j]][ct[i][k]]=min(ds[ct[i][j]][ct[i][k]],ct2[i][j]+ct2[i][k]);//ct[i][j]->ct[i][k]
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //cout<<ds[i][j]<<" ";
            if(ds[i][j]<100000000000&&i!=j){
                v[i].push_back(j);
                cc[i].push_back(ds[i][j]);
            }
        }
        //cout<<endl;
    }
    while(q--){
        int l,r;cin>>l>>r;
        cout<<solve(l,r)+w[l]+w[r]<<endl;
    }
    return 0;
}
