#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=5003;

int c,t;
int n,d;
int x[N];
int f[N][N];
int ans=0;

signed main(){
    //freopen("migrate1.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i=1;i<=n;i++){cin>>x[i];}
        ans=0;
        for(int u=1;u<n;u++){
            memset(f,0,sizeof(f));
            f[u][0]=1;
            for(int i=u;i<=n;i++){
                for(int j=i-1;j>=1&&(x[i]-x[j])<=d;j--){
                    for(int k=1;k<=j;k++){
                        f[i][k]+=f[j][k-1];
                    }
                }
                for(int k=1;k<=i-1;k++){
                    if(f[i][k]==2){ans++;}
                    if(f[i][k]){break;}
                    //cout << f[i][k] << ' ';
                }//cout << '\n';
            }
            //cout << "\n\n";
        }
        //ans/=2;
        cout << ans << '\n';
    }

    return 0;
}


/*
#include <bits/stdc++.h>
#define LL long long
#define int long long

using namespace std;

const int N=5003;
const int INF=0x3f3f3f3f3f3f3f3f;

int c,t;
int n,d;
int x[N];
int head[N],tot=0;
struct node{
    int v,w,next;
}edge[N];
LL dis[N];
int from[N];

inline void add(int x,int y,int w){
    edge[++tot]=(node){y,w,head[x]};
    head[x]=tot;
}


inline void dijistra(int x){
    memset(dis,0x3f,sizeof(dis));
    memset(from,0,sizeof(from));

    priority_queue< pair<LL,int> ,vector< pair<LL,int> >,greater< pair<LL,int> > > q;

    dis[x]=0; from[x]=1;
    q.push(pair<LL,int>(0,x));
    while(!q.empty()){
        int u=q.top().second,dist=q.top().first;
        q.pop();
        //cout << "[dijistra]" << "dist[" << u << "]=" << dist << endl;
        for(int i=head[u];~i;i=edge[i].next){
            int v=edge[i].v,ww=edge[i].w;
            //cout << "[dijistra]" << v << endl;
            if(dist+ww<dis[v]){
                from[v]=from[u];
                dis[v]=dist+ww;
                q.push(pair<LL,int>(dis[v],v));
            }
            if(dist+ww==dis[v]){from[v]+=from[u];}
        }
    }
}

signed main()
{
    //("migrate2.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> c >> t;
    while(t--){
        memset(head,-1,sizeof(head));
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> x[i];
            for(int j=i-1;j>0;j--){
                if(x[i]-x[j]<=d){
                    add(j,i,(x[i]-x[j]));
                }else{break;}
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            dijistra(i);
            for(int j=1;j<=n;j++){
                if(from[j]==2){ans++;}
            }
            for(int i=0;i<=n;i++){
                cout << from[i] << ' ';
            }cout << '\n';
        }
        ans/=2;
        cout << ans << '\n';

    }

    return 0;
}
*/
