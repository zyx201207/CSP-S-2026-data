#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[505][505],w[505][500005],p[500005];
vector<int>mp[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>p[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,ww;
            cin>>x>>ww;
            w[i][x]=ww;
            mp[x].push_back(i);
            //cout<<x<<' '<<ww<<endl;
        }
    }
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=m;i++){
            if(mp[i].size()>1)
        for(int j=0;j<mp[i].size();j++){
            //cout<<mp[i][j]<<' ';
            for(int k=0;k<mp[i].size();k++){
                if(j==k)continue;
                //cout<<i<<' '<<j<<' '<<k<<' '<<w[mp[i][j]][i]<<' '<<w[mp[i][k]][i]<<endl;
                f[mp[i][j]][mp[i][k]]=w[mp[i][j]][i]+w[mp[i][k]][i];
            }
        }//out<<endl;
    }
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    //for(int i=1;i<=n;i++){
     //       for(int j=1;j<=n;j++){
     //           cout<<f[i][j]<<' ';
     //       }cout<<endl;
     //   }
    while(q--){
        int x,y,ans=1e18;
        cin>>x>>y;
        for(auto it:mp[x]){
            for(auto it2:mp[y]){
                ans=min(ans,f[it][it2]+p[x]+p[y]+w[it][x]+w[it2][y]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
