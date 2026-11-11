#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=6e5+10,INF=1e18;
int f[1010][1010],c,n,m,d,q,a,t,x,y,w[maxn],k[maxn],cnt;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++) cin>>w[i];
    cnt=m;
    if(c>=9 && c<=11){//
        ll a1,t1;
        for(int i=1;i<=n;i++){
            cin>>k[i];if(k[i]==1){ cin>>a>>t; continue;}
            cin>>a>>t>>a1>>t1;
            f[a][a1]=f[a1][a]=t+t1;
        }
        for(int i=1;i<=m;i++) f[i][i]=0;
        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                // cout<<f[1][3]<<endl;
            }
        }
        // cout<<f[1][3]<<" "<<f[3][1]<<endl;
        for(int i=1;i<=q;i++){
            cin>>x>>y;
            cout<<w[x]+w[y]+f[x][y]<<'\n';
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        cnt++;
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            f[cnt][a]=f[a][cnt]=t;
        }
    }
    // cout<<f[1][6]<<endl;
    for(int i=1;i<=cnt;i++) f[i][i]=0;
    for(int k=1;k<=cnt;k++){
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=cnt;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            // cout<<f[1][3]<<endl;
        }
    }
    // cout<<f[1][3]<<" "<<f[3][1]<<endl;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<w[x]+w[y]+f[x][y]<<'\n';
    }
    return 0;   
}