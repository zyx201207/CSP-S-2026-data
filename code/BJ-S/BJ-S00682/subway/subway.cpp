#include<map>
#include<vector>
#include<iostream>
using namespace std;
#define ll long long

ll c,n,m,d,q,w[500005],kk[505],dis[505][505],ans,MXN=((ll)(1))<<60;
struct node{
    ll x,y;
};
vector<node>v[500005];
vector<ll>a[505],t[505];
map<ll,ll>mp;
ll f(ll x,ll y){return x*1000000+y;}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>kk[i];
        vector<ll>tmp(kk[i]+1,0);
        a[i]=t[i]=tmp;
        for(int j=1;j<=kk[i];j++)
            cin>>a[i][j]>>t[i][j],
            v[a[i][j]].push_back({i,t[i][j]});
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                dis[i][j]=MXN;
    for(int i=1;i<=m;i++){
        for(auto j:v[i]){
            for(auto k:v[i]){
                if(j.x==k.x)continue;
                if(j.y+k.y<dis[j.x][k.x])
                    dis[j.x][k.x]=j.y+k.y;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        if(mp[f(x,y)]){
            cout<<mp[f(x,y)]<<'\n';
            continue;
        }
        ans=MXN;
        for(auto i:v[x])
            for(auto j:v[y])
                ans=min(ans,dis[i.x][j.x]+i.y+j.y);
        ans+=w[x]+w[y];
        mp[f(x,y)]=mp[f(x,y)]=ans;
        cout<<ans<<'\n';
    }

    return 0;
}
//g++ subway.cpp -o subway -std=c++14 -Wall -O2
//wo yao shang mi huo xing wei