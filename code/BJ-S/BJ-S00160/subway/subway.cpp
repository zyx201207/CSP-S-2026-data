#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,K=5e5+5;
int w[N],a[N][K],t[N][K],k[N];
vector<int> g[N];
int c,n,m,d,q;
void query(int x,int y){
    int ans=w[x]+w[y],xi,yi,xj,yj;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(x==a[i][j]) xi=i,xj=j;
            if(y==a[i][j]) yi=i,yj=j;
        }
    }
    int d=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        int flag=0,w,z;
        for(int j=0;j<g[i].size();j++){
            if(g[i][j]==xi) flag++,w=j;
            if(g[i][j]==yi) flag++,z=j;
        }
        if(flag==2) d=min(t[xi][w]+t[yi][z],d);
    }
    ans+=d;
    cout<<ans*2+(y%2==1)<<endl;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            g[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        query(x,y);
    }
    return 0;
}
