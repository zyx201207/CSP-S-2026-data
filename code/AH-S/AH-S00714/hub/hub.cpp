#include<bits/stdc++.h>
using namespace std;
const int N=20;
vector<int>s;
bool vis[N];
int dd[N][N];
vector<int>e[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){

        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear();
        int ans=1e9;
        memset(dd,0x3f,sizeof dd);
        for(int i=1,x,y;i<n;i++){
            cin>>x>>y;
            dd[x][x]=0;
            dd[y][y]=0;
            dd[x][y]=1;
            dd[y][x]=1;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i!=j&&dd[i][k]<0x3f3f3f3f&&dd[j][k]<0x3f3f3f3f);
                    dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]);
                }
            }
        }
        for(int S1=0;S1<(1<<n);S1++){
            if(__builtin_popcount(S1)==k){
                s.clear();
                memset(vis,0,sizeof vis);
                for(int i=0;i<n;i++){
                    if((S1>>i)&1)s.push_back(i+1),vis[i+1]=1;
                }
                int fg1=0;
                for(auto i:s){
                    bool fg=0;
                    for(auto v:e[i]){
                        if(vis[v]==1){
                            fg=1;
                            break;
                        }
                    }
                    if(fg==0){
                        fg1++;
                    }
                }
                if(fg1>2&&(!(fg1==k&&k<=2)))continue;
                //for(auto i:s){
                //    cout<<i<<" ";
                //
                int d2=0;
                for(int i=1;i<=n;i++){
                    if((S1>>(i-1))&1)continue;
                    int d=1e9;
                    for(auto j:s){
                        d=min(d,dd[i][j]);
                    }
                    d2=max(d2,d);
                }
                //cout<<d2<<" ";
                ans=min(d2,ans);
                //cout<<'\n';
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
