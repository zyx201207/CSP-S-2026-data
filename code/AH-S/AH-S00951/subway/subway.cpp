#include<iostream>
#include<cstdio>
#include<vector>
#define MAXM 500010
#define ll long long
using namespace std;

struct node{
    ll to,was;
};

ll c,n,m,d,q;
ll w[MAXM];
ll fld[510][510];//subway to subway
vector<node> G[MAXM];//station to subway
ll k[510];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            fld[i][j]=1e18;
            if(i==j) fld[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            ll a,b;
            scanf("%lld %lld",&a,&b);
            G[a].push_back((node){i,b});
        }
    }
    for(int i=1;i<=m;i++){
        for(int t1=0;t1<G[i].size();t1++){
            for(int t2=t1+1;t2<G[i].size();t2++){
                ll nx=G[i][t1].to,ny=G[i][t2].to;
                fld[nx][ny]=min(fld[nx][ny],G[i][t1].was+G[i][t2].was);
                fld[ny][nx]=fld[nx][ny];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(k==i) continue;
            for(int j=i+1;j<=n;j++){
                fld[i][j]=min(fld[i][j],fld[i][k]+fld[k][j]);
                fld[j][i]=fld[i][j];
            }
        }
    }
    for(int i=1;i<=q;i++){
        ll yx,yy;
        cin>>yx>>yy;
        ll ans=1e18;
        for(int t1=0;t1<G[yx].size();t1++){
            for(int t2=0;t2<G[yy].size();t2++){
                ll now=G[yx][t1].was+G[yy][t2].was+fld[G[yx][t1].to][G[yy][t2].to];
                ans=min(ans,now);
            }
        }
        ans=ans+w[yx]+w[yy];
        cout<<ans<<endl;
    }
    return 0;
}
