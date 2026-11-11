#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,t,C;
const int N=1e3+10,M=2e6+10;
bool a[N][N];
int dis[N];
int fa[N],dep[M],c[N];
bool f[N];
bool ff[M];
void www(){
    int ans=0;
    while(t--){
        memset(a,false,sizeof(a));
        memset(ff,false,sizeof(ff));
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&dis[i]);
        }
        if(d==1){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dis[j]-dis[i]<=d){
                    ff[j]=true;
                }
            }
        }
        vector<int> v;
        for(int i=1;i<=n;i++){
            if(!ff[i]){
                v.push_back(i);
            }
        }
        v.push_back(n+1);
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]>=d*2) ans+=v[i]-v[i-1]-d*2+1;
        }
        cout<<ans<<endl;
    }
}
void w(int root,int depth){
    queue<int> q;
    q.push(root);
    f[root]=true;
    while(q.empty()==false){
        int h=q.front();
        q.pop();
        f[h]=false;
        for(int i=1;i<=n;i++){
            if(a[h][i]&&dep[i]==0&&!f[i]){
                dep[i]=dep[h]+1;
                q.push(i);
            }else if(a[h][i]&&dep[i]==dep[h]+1){
                c[i]++;
            }
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&C,&t);
    int ans=0;
    if(C>=10){
        www();
        return 0;
    }
    while(t--){
        memset(a,false,sizeof(a));
        ans=0;
        scanf("%lld%lld",&n,&d);
        if(d==1){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            scanf("%lld",&dis[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dis[j]-dis[i]<=d){
                    a[i][j]=true;
                    a[j][i]=true;
                }
            }
        }
        for(int i=1;i<=n;i++){
            memset(dep,0,sizeof(dep));
            for(int j=1;j<=n;j++){
                fa[j]=j;
            }
            memset(c,0,sizeof(c));
            dep[i]=1;
            w(i,1);
            for(int j=1;j<=n;j++){
                //cout<<c[j]<<" ";
                if(c[j]==1){
                    ans++;
                }
            }
            //cout<<endl;
        }
        ans=ans/2;
        printf("%lld\n",ans);
    }
    return 0;
}

