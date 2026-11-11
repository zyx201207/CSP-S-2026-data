#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;
typedef long long ll;
const int N=2e6+5;
int C, T;
int n;
ll D;
ll ar[N];
int nxt[N];

namespace s1{
    int dis[N], cnt[N];

    void djstra(int s){
        mem(dis,0x3f);
        mem(cnt,0);
        struct qnode{
            int u,d;
            bool operator<(const qnode &oth) const{
                return d>oth.d;
            }
        };
        priority_queue<qnode> q;
        q.push({s,dis[s]=0});
        cnt[s]=1;
        while (q.size()){
            qnode cur=q.top();
            q.pop();
            int u=cur.u,d=cur.d;
            if (d>dis[u])
                continue;
            for (int v=u+1; v<=n&&ar[v]-ar[u]<=D; v++){
                if (d+1<dis[v]){
                    q.push({v,dis[v]=d+1});
                    cnt[v]=cnt[u];
                }
                else if (d+1==dis[v]){
                    cnt[v]+=cnt[u];
                }
            }
        }
    }

    void solve(){
        int ans=0;
        for (int i=1; i<=n; i++){
            djstra(i);
            for (int j=i+1; j<=n; j++){
                if (cnt[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}

namespace scha{
    void solve(){
        int t;
        for (int i=1; i<=n; i++){
            if (ar[i]-ar[1]>D)
                break;
            t=i-1;
        }
        if ((t<<1)>n){
            cout<<0<<'\n';
        }
        else{
            int ans=n-(t<<1)+1;
            cout<<ans<<"\n";
        }
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>C>>T;
    while (T--){
        cin>>n>>D;
        bool fcha=1;
        for (int i=1; i<=n; i++){
            cin>>ar[i];
            if (i>=3){
                if (ar[i]-ar[i-1]!=ar[i-1]-ar[i-2]){
                    fcha=0;
                }
            }
        }
        if (n<=5000){
            s1::solve();
            continue;
        }
        if (fcha){
            scha::solve();
            continue;
        }
        s1::solve();
        // int r=1;
        // for (int i=1; i<=n; i++){
        //     while (x[r]-x[i]<=D){
        //         r++;
        //     }
        //     nxt[i]=r-1-i;
        // }
    }
    return 0;
}