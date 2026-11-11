#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int c,n,m,d,q,u,v;
ll t1[500010];
ll w[1010][1010];
ll a[1010],t[1010];
ll p[500010][3];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    memset(w,0x3f,sizeof(w));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>t1[i];
    }
        for(int i=1;i<=m;i++) w[i][i]=0;
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
            for(int j=1;j<=k;j++){
                for(int l=j+1;l<=k;l++){
                    /*
                    if(w[a[j]][a[l]]==inf){
                        g[a[j]].push_back(a[l]);
                        g[a[l]].push_back(a[j]);
                    }
                    */
                    w[a[j]][a[l]]=w[a[l]][a[j]]=min(w[a[j]][a[l]],t[j]+t[l]);
                }
            }
        }
        /*
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                cout<<w[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
                }
            }
        }
        /*
        cout<<endl;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                cout<<w[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        while(q--){
            cin>>u>>v;
            cout<<t1[u]+t1[v]+w[u][v]<<"\n";
        }
    return 0;
}
