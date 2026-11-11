#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#define ll long long
using namespace std;
const int M=500005,N=505;
int w[M],len[N];
struct node{
    int id,t;
};
vector<node> P[M];
ll mp[N][N];
ll times(int x,int y){
    ll ans=0;
    ans+=(w[x]+w[y]);
    ll minn=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<P[x].size();i++){
        for(int j=0;j<P[y].size();j++){
            minn=min(minn,P[x][i].t+P[y][j].t+mp[P[x][i].id][P[y][j].id]);
        }
    }
    return ans+minn;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i!=j) mp[i][j]=0x3f3f3f3f3f3f3f3f;
        }
    }
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",w+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",len+i);
        for(int j=0;j<len[i];j++){
            int x,y;
            scanf("%d%d",&x,&y);
            P[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        if(P[i].size()>=2){
            for(int j=0;j<P[i].size();j++){
                for(int k=j+1;k<P[i].size();k++){
                    mp[P[i][j].id][P[i][k].id]=mp[P[i][k].id][P[i][j].id]=min(mp[P[i][j].id][P[i][k].id],(ll)P[i][j].t+(ll)P[i][k].t);
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }/*
    for(int i=1;i<=m;i++){
        cout<<i<<":\n";
        for(int j=0;j<P[i].size();j++) cout<<P[i][j].id<<' '<<P[i][j].t<<'\n';
    }*/
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",times(x,y));
    }
    return 0;
}
