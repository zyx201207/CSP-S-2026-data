#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,e[500005],k[505],a,t,l[500005][25],ld[500005][25],lns[500005],mp[505][505],x,y,ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            mp[i][j]=10e17;
        }
    }
    for(int i=1;i<=500;i++){
        mp[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>e[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            lns[a]++;
            l[a][lns[a]]=t;
            ld[a][lns[a]]=i;
        }
    }
    for(int i=1;i<=m;i++){
        if(lns[i]>1){
            for(int j=1;j<=lns[i];j++){
                for(int k=1;k<=lns[i];k++){
                    mp[ld[i][j]][ld[i][k]]=min(mp[ld[i][j]][ld[i][k]],l[i][j]+l[i][k]);
                    mp[ld[i][k]][ld[i][j]]=mp[ld[i][j]][ld[i][k]];
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i!=j&&i!=k&&j!=k){
                    mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
                    mp[j][i]=mp[i][j];
                }
            }
        }
    }
    for(int r=1;r<=q;r++){
        cin>>x>>y;
        ans=10e17;
        for(int i=1;i<=lns[x];i++){
            for(int j=1;j<=lns[y];j++){
                ans=min(ans,e[x]+e[y]+l[x][i]+l[y][j]+mp[ld[x][i]][ld[y][j]]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
