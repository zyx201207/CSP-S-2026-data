#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+7,M=5007;
const int LG=22;
int c,t;
int n;
ll d;
ll x[N];
int nxt[LG][N],pnxt[LG][N];
vector<int>dag[N];
inline int dis(int x,int y){
    int ans=0;
    if(pnxt[LG-1][x]<y)return -1;
    if(x==y)return 0;
    for(int i=LG-1;i;i--)
        if(pnxt[i-1][x]<y){
            ans|=(1<<i);
            x=nxt[i][x];
        }
    if(x<y)++ans,x=nxt[0][x];
    return ans;
}
ll res=0;
// task 1-10
int deg[N];
queue<int>qu;
int f[N];
inline void solve(int p){
    for(int i=p;i<=n;i++)dag[i].clear(),deg[i]=0,f[i]=0;
    for(int i=p;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(dis(i,j)>1||dis(i,j)==-1)break;
            if(dis(p,i)+dis(i,j)==dis(p,j))dag[i].emplace_back(j),++deg[j];
        }
    }
    qu.emplace(p);
    f[p]=1;
    while(!qu.empty()){
        int tp=qu.front();
        res+=(f[tp]==2);
        qu.pop();
        for(int v:dag[tp]){
            f[v]+=f[tp];
            --deg[v];
            if(!deg[v]&&f[v]<=2)qu.emplace(v);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        res=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(n<=5000){
            for(int i=1;i<=n;i++){
                nxt[0][i]=lower_bound(x+1,x+1+n,x[i]+d)-x;
                if(nxt[0][i]<=n&&x[nxt[0][i]]-x[i]>d)--nxt[0][i];
            }
            nxt[0][n+1]=n+1;
            for(int j=1;j<LG;j++)
                for(int i=1;i<=n+1;i++)
                    nxt[j][i]=nxt[j-1][nxt[j-1][i]];
            for(int i=1;i<=n+1;i++)pnxt[0][i]=nxt[0][i];
            for(int j=1;j<LG;j++)
                for(int i=1;i<=n+1;i++)
                    pnxt[j][i]=nxt[j][pnxt[j-1][i]];
            for(int i=1;i<=n;i++){
                solve(i);
            }
            cout<<res<<'\n';
        }else{
            ll k=llabs(x[2]-x[1]);
            ll len=d/k;
            if(len==0||len==1)cout<<0<<'\n';
            else{
                cout<<max(n-2ll*len+1,0ll)<<'\n';
            }
        }
    }
    return 0;
}