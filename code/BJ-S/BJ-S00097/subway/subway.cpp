#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXM=5e5+5;
const int MAXN=505;

int c,n,m,d,q,w[MAXM],k[MAXN],a[MAXM],t[MAXM],tot=0,dis[505][505],len[MAXM][25],l[MAXM][25],num[MAXM];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(w,0x3f,sizeof(w));
    for(int i=1;i<=m;i++)   cin>>w[i];
    memset(len,0x3f,sizeof(len));

    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            tot++;
            cin>>a[tot]>>t[tot];
            num[a[tot]]++;l[a[tot]][num[a[tot]]]=i;len[a[tot]][num[a[tot]]]=t[tot];
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)   dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<num[i];j++){
            for(int k=j+1;k<=num[i];k++){
                int x=l[i][j],y=l[i][k];
                dis[x][y]=min(dis[x][y],len[i][j]+len[i][k]);
                dis[y][x]=min(dis[y][x],len[i][j]+len[i][k]);
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]+dis[j][k]<dis[i][j])   dis[i][j]=dis[i][k]+dis[j][k];
            }
        }
    }

    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=n;j++){
    //        cout<<dis[i][j]<<' ';
    //    }
    //    cout<<'\n';
    //}
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=10000000000000000;
        for(int j=1;j<=num[x];j++){
            for(int k=1;k<=num[y];k++){
                int tmp=dis[l[x][j]][l[y][k]]+len[x][j]+len[y][k]+w[x]+w[y];
                ans=min(ans,tmp);
        //cout<<l[x][j]<<' '<<l[y][k]<<' '<<len[x][j]<<' '<<len[y][k]<<' '<<w[x]<<' '<<w[y]<<' '<<tmp<<' ';
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
