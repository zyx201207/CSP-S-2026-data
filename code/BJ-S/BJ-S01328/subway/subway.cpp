#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+11,M=5e5+11;
int c,n,m,d,q,w[M],k,a,t,tong[M],f[N][N];
struct node{
    int tim,line;
};
vector<node> v[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
  //  cout<<1;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            //cout<<a<<t<<"\n";
            tong[a]++;
            v[a].push_back({t,i});
            //cout<<a<<t<<"\n";
        }
        //cout<<i;
    }
    //cout<<1;
    for(int i=1;i<=m;i++){
        if(tong[i]>=1){
            int len=v[i].size();
            for(int j=0;j<len;j++){
                for(int k=j+1;k<len;k++){
                    int val=v[i][j].tim+v[i][k].tim;
                    int x=v[i][j].line,y=v[i][k].line;
                    if(x==y)continue;
                    if(f[x][y]!=0)f[x][y]=min(val,f[x][y]);
                    else f[x][y]=val;
                    f[y][x]=f[x][y];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i!=j&&j!=k&&i!=k){
                    if(f[i][k]!=0&&f[k][j]!=0){
                        if(f[i][j]==0)f[i][j]=f[i][k]+f[k][j];
                        else f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                    }
                }
            }
        }
    }
    for(int o=1;o<=q;o++){
    //    cout<<1;
        int from,to,ans=0,minn=2e9+11;
        cin>>from>>to;
        ans+=w[from]+w[to];
        for(int i=0;i<v[from].size();i++){
            for(int j=0;j<v[to].size();j++){
                int valx=v[from][i].tim,valy=v[to][j].tim,x=v[from][i].line,y=v[to][j].line;
                minn=min(f[x][y]+valx+valy,minn);
         //       cout<<x<<" "<<y<<" "<<valx<<" "<<valy<<" "<<f[x][y]<<"\n";
            }
        }
        ans+=minn;
        cout<<ans<<"\n";
    }
    return 0;
}
//time():O(max(m(n^2),n^3));
