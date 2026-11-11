#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q,kk;
int w[500005];
ll dis[505][505];
int ta[500005][21],tt[500005][21];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>kk;
        int tmpa,tmpt;
        for(int j=1;j<=kk;j++){
            cin>>tmpa>>tmpt;
            ta[tmpa][++ta[tmpa][0]]=i;tt[tmpa][ta[tmpa][0]]=tmpt;
        }
        //cout<<ta[tmpa][ta[tmpa][0]]<<' ' <<tt[tmpa][ta[tmpa][0]]<<endl;
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=ta[i][0];j++){
            for(int k=j+1;k<=ta[i][0];k++){
                dis[ta[i][j]][ta[i][k]]=min(dis[ta[i][j]][ta[i][k]],(ll)(tt[i][j]+tt[i][k]));
                dis[ta[i][k]][ta[i][j]]=dis[ta[i][j]][ta[i][k]];
            }
        }
    }
    /*for(int i=1;i<=m;i++){
        cout<<ta[i][0]<<endl;
        for(int j=1;j<=ta[i][0];j++) cout<<ta[i][j]<<' ';
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            for(int k=j+1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[k][i]);
                dis[k][j]=dis[j][k];
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<dis[i][j]<<' ';
        cout<<endl;
    }*/
    int x,y;
    ll ans;
    //cout<<tt[1][1]<<' '<<tt[3][1]<<' '<<dis[1][2]<<endl;
    for(int i=1;i<=q;i++){
        ans=1000000000000000000;
        cin>>x>>y;
        for(int j=1;j<=ta[x][0];j++){
            for(int k=1;k<=ta[y][0];k++){
                //cout<<ta[x][j]<<' '<<ta[y][k]<<endl;
                if(ta[x][j]==ta[y][k]) ans=min(ans,(ll)(tt[x][j]+tt[y][k]));
                else ans=min(ans,tt[x][j]+tt[y][k]+dis[ta[x][j]][ta[y][k]]);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
