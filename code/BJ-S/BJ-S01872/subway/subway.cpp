#include<bits/stdc++.h>
using namespace std;

long long n,m,p[500005],k[505],t[500005],a[500005];
long long w[505][505],d[505][505],cnt;
long long l[500005];
struct stage{
    int id;
    long long w;
}s[500005][25];

void dji(int x){
    priority_queue < greater < pair<long long,int> > ,vector <pair<long long,int> > > q;
    q.push(make_pair(0,x));
    while(!q.empty()){
        pair <long long,int> q1=q.top();
        q.pop();
        int z=q1.first,u=q1.second;
        for(int i=1; i<=n; i++){
            if(u==i||x==i)continue;
            if(z+w[u][i]<d[x][i]){
                d[x][i]=z+w[u][i];
                q.push(make_pair(d[x][i],i));
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long C,D,Q;
    cin >> C >> n >> m >> D >> Q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[i][j]=0x3f3f3f3f;
            w[i][j]=0x3f3f3f3f;
            if(i==j)d[i][j]=0;
        }
    }
    for(int i=1; i<=m; i++){
        cin >> p[i];
    }
    for(int i=1; i<=n; i++){
        cin >> k[i];
        for(int j=1; j<=k[i]; j++){
            cin >> a[j] >> t[i];
            s[a[j]][++l[a[j]]].id=i;
            s[a[j]][l[a[j]]].w=t[i];
        }
    }
    for(int i=1; i<=m; i++){
        for(int j1=1; j1<=l[i]; j1++){
            for(int j2=1; j2<=l[i]; j2++){
                if(j1==j2)continue;
                w[s[i][j1].id][s[i][j2].id]=min( s[i][j1].w+s[i][j2].w , w[s[i][j1].id][s[i][j2].id] );
                w[s[i][j2].id][s[i][j1].id]=w[s[i][j1].id][s[i][j2].id];
            }
        }
    }
    for(int i=1; i<=n; i++){
        dji(i);
    }
    while(Q--){
        int u,v;
        cin >> u >> v;
        cnt=0x3f3f3f3f;
        for(int i=1; i<=l[u]; i++){
            for(int j=1; j<=l[v]; j++){
                cnt=min(cnt,s[u][i].w+d[s[u][i].id][s[v][j].id]+s[v][j].w);
            }
        }
        printf("%lld\n",cnt+p[u]+p[v]);
    }

    return 0;
}
