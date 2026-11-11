#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,dd,q,w[500010],d[210][410],k[210],floyd[410][410],t[210][410];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>dd>>q;
    for(int i=1; i<=m; i++){
        cin>>w[i];
    }
    if(c<=8){
        memset(floyd,0x3f,sizeof floyd);
        for(int i=1; i<=n; i++){
            cin>>k[i];
            for(int j=1; j<=k[i]; j++){
                cin>>d[i][j]>>t[i][j];
            }
            for(int j=1; j<=k[i]; j++){
                for(int kk=1; kk<=k[i]; kk++){
                    floyd[d[i][j]][d[i][kk]]=t[i][min(j,kk)]+t[i][max(j,kk)];
                }
            }
        }
        for(int kk=1; kk<=m; kk++){
            for(int i=1; i<=m; i++){
                for(int j=1; j<=m; j++){
                    floyd[i][j]=min(floyd[i][j],floyd[i][kk]+floyd[kk][j]);
                }
            }
        }
        while(q--){
            int s,t;
            cin>>s>>t;
            cout<<w[s]+w[t]+floyd[s][t]<<'\n';
        }
        return 0;
    }

    return 0;
}//n<=200,m<=400,d<=20,q<=200   ->   32
