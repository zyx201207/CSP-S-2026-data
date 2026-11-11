#include <bits/stdc++.h>

using namespace std;
struct node{
    int u;
    int v;
};
int c,n,m,d,q;
int tkou[500005];
vector <node> mp[500005];
int a[50005];
int t[50005];
bool visit[50005];
int digi(int x,int y){
    int minn=20000000;
    for(int i=0;i<mp[x].size();i++){
        int z=mp[x][i].u;
        int v=mp[x][i].v;
        if(z==y) return v;
        if(visit[z]==0){
            visit[z]=1;
            minn=min(minn,v+digi(z,y));
        }
    }
    return minn;
}
void init_(){
    for(int i=0;i<=50005;i++){
        visit[i]=0;
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>tkou[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>a[i]>>t[i];
        }
        for(int i=1;i<=k;i++){
            for(int j=i+1;j<=k;j++){
                mp[a[i]].push_back({a[j],t[i]+t[j]});
                mp[a[j]].push_back({a[i],t[i]+t[j]});
            }
        }
    }
    for(int i=1;i<=q;i++){
        init_();
        int x,y;
        cin>>x>>y;
        visit[x]=1;
        cout<<tkou[x]+tkou[y]+digi(x,y)<<endl;
    }
    return 0;
}