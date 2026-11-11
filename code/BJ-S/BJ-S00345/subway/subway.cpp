#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const long long MAXN=500+10,MAXM=5e5+10,d=20+10;
long long l[MAXN][MAXN],w[MAXM];
struct node{
    long long a;
    long long t;
};
vector<vector<node> >v(MAXM);

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }

    for(long long i=0;i<n;i++){
        long long k;
        cin>>k;
        for(long long j=0;j<k;j++){
            long long a,t;
            cin>>a>>t;
            v[a].push_back((node){i,t});
        }
    }

    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            l[i][j]=1e18;
        }
        l[i][i]=0;
    }

    for(long long i=1;i<=m;i++){
        for(long long j=0;j<v[i].size();j++){
            for(long long k=0;k<j;k++){
                l[v[i][j].a][v[i][k].a]=min(l[v[i][j].a][v[i][k].a],v[i][j].t+v[i][k].t);
                l[v[i][k].a][v[i][j].a]=l[v[i][j].a][v[i][k].a];
            }
        }
    }

    for(long long i=0;i<n;i++)
        for(long long j=0;j<n;j++)
            for(long long k=0;k<n;k++)
                l[j][k]=min(l[j][k],l[j][i]+l[i][k]);

    for(long long i=0;i<q;i++){
        long long x,y;
        cin>>x>>y;
        long long ans=1e18;
        for(long long j=0;j<v[x].size();j++)
            for(long long k=0;k<v[y].size();k++)
                ans=min(ans,v[x][j].t+l[v[x][j].a][v[y][k].a]+v[y][k].t);
        cout<<ans+w[x]+w[y]<<endl;
    }

    return 0;
}
