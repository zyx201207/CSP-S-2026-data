#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N=505,M=5e5+5,A=5e6;
const LL INF=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,ttt;
int w[M];
int head[A],tot=0;
struct node{
    int v,w,next;
}edge[A];
LL dis[M];
//LL f[1503][1503];

inline void add(int x,int y,int w){
    edge[++tot]=(node){y,w,head[x]};
    head[x]=tot;
}
/*
inline void finit(){
    for(int i=1;i<=(n+m);i++){
        for(int j=1;j<=(n+m);j++){
            f[i][j]=INF;
        }
    }
}*/

inline void solve_dijistra(int x,int y){
    memset(dis,0x3f,sizeof(dis));

    priority_queue< pair<LL,int> ,vector< pair<LL,int> >,greater< pair<LL,int> > > q;

    dis[x]=(LL)w[x];
    q.push(pair<LL,int>(w[x],x));
    while(!q.empty()){
        int u=q.top().second,dist=q.top().first;
        q.pop();
        //cout << "[dijistra]" << "dist[" << u << "]=" << dist << endl;
        for(int i=head[u];~i;i=edge[i].next){
            int v=edge[i].v,ww=edge[i].w;
            //cout << "[dijistra]" << v << endl;
            if(dist+ww<dis[v]){
                dis[v]=dist+ww;
                q.push(pair<LL,int>(dis[v],v));
            }
        }
    }
    cout << dis[y]+w[y] << '\n';
}
/*
inline void solve_f(){
    for(int i=1;i<=(n+m);i++){f[i][i]=0;}

    for(int k=1;k<=(n+m);k++){
        for(int i=1;i<=(n+m);i++){
            for(int j=1;j<=(n+m);j++){
                f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
            }
        }
    }

    int x,y;
    while(ttt--){
        cin >> x >> y;
        cout << f[x][y] << endl;
    }

}
*/
int main()
{
    //freopen("subway5.in","r",stdin);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    memset(head,-1,sizeof(head));

    cin >> c >> n >> m >> d >> ttt;
    for(int i=1;i<=m;i++){cin>>w[i];}
    //if(ttt>2000){finit();}
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        while(k--){
            int aaa,ttt;
            cin>>aaa>>ttt;
            add(aaa,m+i,ttt); add(m+i,aaa,ttt);
            //else{f[aaa][m+i]=f[m+i][aaa]=ttt;}
        }
    }

        while(ttt--){
            int x,y;
            cin >> x >> y;
            solve_dijistra(x,y);
        }
    //else{solve_f();}
    //else if(9<=c&&c<=11){
    //    solve_f();
    //}


    return 0;
}
