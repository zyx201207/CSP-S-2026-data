#include<bits/stdc++.h>
using namespace std;
const int M=500005;
int c,n,m,d,q;
int w[M],k[505],a[505][M],t[505][M];
vector<int> s[M];
long long g[505][505];
long long x,y,ans=-1;
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
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
            s[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++)g[i][i]=0;
    for(int i=1;i<=m;i++){
        int len=s[i].size();
        if(len==1)continue;
        for(int j=0;j<len;j++){
            for(int k=0;k<len;k++){
                int kk=s[i][k],jj=s[i][j];
                if(kk==jj)continue;
                if(g[jj][kk]==-1||g[jj][kk]>t[jj][i]+t[kk][i]){
                    g[jj][kk]=t[jj][i]+t[kk][i];
                }
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][k]==-1||g[k][j]==-1)continue;
                if(g[i][j]==-1||g[i][j]>g[i][k]+g[k][j]){
                    g[i][j]=g[i][k]+g[k][j];
                }
            }
        }
    }
    while(q--){
        cin>>x>>y;
        ans=-1;
        for(int i=0;i<s[x].size();i++){
            for(int j=0;j<s[y].size();j++){
                int ii=s[x][i],jj=s[y][j];
                if(ans==-1||ans>g[ii][jj]+t[ii][x]+t[jj][y]){
                    ans=g[ii][jj]+t[ii][x]+t[jj][y];
                }
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
