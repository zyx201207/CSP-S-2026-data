#include<bits/stdc++.h>
using namespace std;
#define ll long long
int w[500010];
struct edge{
    int w,v,wh;
};
vector<edge>r[510];
vector<vector<edge>>sta;
ll dis[510][510];
int main(){
    //int o;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    /*if(c==0){
        cout<<32<<'\n'<<17;
        return 0;
    }*/for(int i=1;i<=m;++i)scanf("%d",w+i);
    //*O(alpha(n))*
    sta.resize(m);
    for(int i=0;i<n;++i){
        int k;
        scanf("%d",&k);
        for(int j=1,r1,r2;j<=k;++j){
            scanf("%d%d",&r1,&r2);
            r[i].push_back({r2,r1-1,1});
            sta[r1-1].push_back({r2,i,0});
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i!=j){
                dis[i][j]=-1;
                dis[j][i]=-1;
            }
        }
    }
    /*for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<dis[i][j]<<' ';
        }cout<<'\n';
    }*/
    for(int i=0;i<n;++i){
        for(edge it:r[i]){
            for(edge iit:sta[it.v]){
                if(dis[i][iit.v]==-1||dis[i][iit.v]>it.w+iit.w){
                    dis[i][iit.v]=it.w+iit.w;
                    dis[iit.v][i]=it.w+iit.w;
                }
            }
        }
    }
    /*for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<dis[i][j]<<' ';
        }cout<<'\n';
    }*/
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                if(dis[i][k]!=-1&&dis[k][j]!=-1&&(dis[i][j]==-1||dis[i][j]>dis[i][k]+dis[k][j])){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    dis[j][i]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    /*for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<dis[i][j]<<' ';
        }cout<<'\n';
    }*/
    while(q--){
        ll x,y;
        scanf("%lld%lld",&x,&y);
        ll ans=w[x]+w[y],mi=1e18;
        --x,--y;
        for(edge it:sta[x]){
            for(edge iit:sta[y]){
                ll rr=dis[it.v][iit.v]+it.w+iit.w;
                //cout<<it.v<<' '<<iit.v<<' '<<rr<<'\n';
                if(rr<mi)mi=rr;
            }
        }printf("%lld\n",ans+mi);
    }return 0;
}