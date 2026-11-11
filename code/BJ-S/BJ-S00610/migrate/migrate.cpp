#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
int c, t, n, d, dis[N], a[N], l[N], r[N], k[N];
struct aaa{
    int u, step;
};
void bfs(int str){
    queue<aaa> q;
    q.push({str,0});
    while(!q.empty()){
        aaa now=q.front();
        q.pop();
        int u=now.u;
        int st=now.step;
        if(dis[u]>st){
            dis[u]=st;
            k[u]=1;
        }
        else if(dis[u]==st) k[u]++;
        for(int v=u-1;v>=l[u];v--){
            q.push({v,st+1});
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    if(c<=10){
        while(t--){
            cin >> n >> d;
            memset(k,0,sizeof k);
            memset(dis,0x3f,sizeof dis);
            for(int i=1;i<=n;i++){
                cin >> a[i];
            }
            for(int i=1,j=1;i<=n;i++){
                while(j<=i&&j<n&&a[i]-a[j]>d) j++;
                l[i]=j;
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=i;j++) k[j]=0, dis[j]=1e18;
                bfs(i);
                for(int j=1;j<i;j++) if(k[j]==2) ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
