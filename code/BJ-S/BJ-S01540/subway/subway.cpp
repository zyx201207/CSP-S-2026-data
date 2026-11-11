#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505;
const int maxm=500005;
const ll inf=(ll)4e18;
int c,n,m,d,q;
int deg[maxm],line[maxm][25],ts[maxm][25];
ll dd[maxn][maxn],w[maxm];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=0;i<n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int a,t;cin>>a>>t;
            line[a][deg[a]]=i;
            ts[a][deg[a]++]=t;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j)dd[i][j]=inf;
    for(int i=1;i<=m;i++){
        for(int j=0;j<deg[i];j++){
            for(int k=0;k<deg[i];k++){
                if(j==k)continue;
                dd[line[i][j]][line[i][k]]=min(dd[line[i][j]][line[i][k]],(ll)(ts[i][j]+ts[i][k]));
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dd[j][i]==inf)continue;
            ll tmp=dd[j][i];
            for(int k=0;k<n;k++){
                if(dd[i][k]==inf)continue;
                dd[j][k]=min(dd[j][k],dd[i][k]+tmp);
            }
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        ll res=inf;
        for(int i=0;i<deg[x];i++){
            for(int j=0;j<deg[y];j++){
                if(dd[line[x][i]][line[y][j]]==inf)continue;
                ll cur=dd[line[x][i]][line[y][j]]+ts[x][i]+ts[y][j];
                res=min(res,cur);
            }
        }
        cout<<w[x]+w[y]+res<<endl;
    }
    return 0;
}
//窝药听法老新专辑。
//窝药听AkiniJing的EP