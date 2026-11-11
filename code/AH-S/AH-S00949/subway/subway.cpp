#include<bits/stdc++.h>
using namespace std;
int w[505],t[505][505],d[505][505],tim[505][505];
bool flag[505];
vector<int> to,z[505];
void solve(int x,int y,int sum){
    d[x][y]=min(d[x][y],sum);
    flag[y]=true;
    for(int i=0;i<z[y].size();i++){
        if(!flag[z[y][i]]){
            solve(x,z[y][i],sum+tim[y][z[y][i]]);
        }
    }
    flag[y]=false;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,m,n,d1,p,x1,y1;
    cin>>c>>n>>m>>d1>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,T;
            cin>>a>>T;
            to.push_back(a);
            t[i][j]=T;
        }
        for(int j=0;j<to.size();j++){
            for(int W=j;W<to.size();W++){
                z[to[j]].push_back(to[W]);
                z[to[W]].push_back(to[j]);
                tim[j][W]=w[j]+t[i][W];
                tim[W][j]=w[W]+t[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=0x3f3f3f3f;
        }
    }
    for(int i=1;i<=n;i++){
        solve(i,i,0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<d[i][j]<<" ";
        }
    }
    for(int i=1;i<=p;i++){
        cin>>x1>>y1;
        cout<<d[x1][y1]<<endl;
    }
    return 0;
}
