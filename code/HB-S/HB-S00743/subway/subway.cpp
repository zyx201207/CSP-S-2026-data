#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
/*
n lines, m stations!!!!!!!!!!!!!!!!!!
*/
long long to_zt[500005],k[505];
vector<int> a[505];
vector<long long> t[505];
long long f[1005][1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>to_zt[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    if(c>=7&&c<=11){
        memset(f,0x3f,sizeof(f));
        for(int i=1;i<=m;i++) f[i][i]=0;
        for(int i=1;i<=n;i++){
            if(k[i]==2){
                f[a[i][0]][a[i][1]]=min(f[a[i][0]][a[i][1]],t[i][0]+t[i][1]);
                f[a[i][1]][a[i][0]]=min(f[a[i][1]][a[i][0]],t[i][0]+t[i][1]);
            }
        }
        for(int p=1;p<=m;p++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
                }
            }
        }
        while(q--){
            cin>>x>>y;
            cout<<to_zt[x]+to_zt[y]+f[x][y]<<"\n";
        }
    }
    else{
        while(q--) cout<<"0\n";
    }
}