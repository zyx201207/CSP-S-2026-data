#include<iostream>
#include<cstring>
using namespace std;
const int N=5e5+5;
const int F=2e3+5;
int w[N],floyd[F][F];
int a[F][F];
int k[N];
int T;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(floyd,0x3f,sizeof(floyd));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int prev,data;
        for(int j=1;j<=k[i];j++){
            cin>>data>>T;
            a[i][j]=data;
            if(j>=2){
                floyd[data][prev]=floyd[prev][data]=0;
            }
            prev=data;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int p=1;p<=k[i];p++){
                floyd[a[i][p]][a[i][p]]=T;
                for(int q=1;q<=k[j];q++){
                    floyd[a[j][q]][a[j][q]]=T;
                    if(a[i][p]==a[j][q]){
                        floyd[a[i][p]][a[j][q]]=min(floyd[a[i][p]][a[i][p]]+T+T+floyd[a[j][q]][a[j][q]],floyd[a[i][p]][a[j][q]]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i+2;j<=m;j++){
            for(int t=i+1;t<j;t++){
                floyd[i][j]=floyd[j][i]=min(floyd[i][j],floyd[i][t]+floyd[t][t]+floyd[t][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<floyd[u][v]+w[u]+w[v]+2*T<<'\n';
    }
    return 0;
}
