#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=2e6+6;
int c,T,n;
ll d,x[N];

namespace brute {
    const int N_=300+6;
    int dis[N_][N_],cnt[N_][N_];

    int qry() {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (abs(x[i]-x[j])>d) dis[i][j]=N_;
                else if (i!=j) dis[i][j]=1;
                else dis[i][j]=0;
                cnt[i][j]=0;
            }
        }
        for (int k=1;k<=n;k++) {
            for (int i=1;i<=n;i++) {
                if (i==k||dis[i][k]==N_) continue;
                for (int j=1;j<=n;j++) {
                    if (j==k||j==i||dis[k][j]==N_) continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][i]);
                }
            }
        }
        int res=0;
        for (int k=1;k<=n;k++) {
            for (int i=1;i<=n;i++) {
                if (i==k||dis[i][k]==N_) continue;
                for (int j=i+1;j<=n;j++) {
                    if (j==k||j==i||dis[k][j]==N_) continue;
                    cnt[i][j]+=(dis[i][j]==dis[i][k]+dis[k][i]);
                }
            }
        }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                res+=(cnt[i][j]==2);
        return res;
    }
};

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while (T--) {
        cin>>n>>d;
        for (int i=1;i<=n;i++) cin>>x[i];
        if (c<=6) {
            using namespace brute;
            cout<<qry()<<'\n';
        } else {
            cout<<"0\n";
        }
    }
    return 0;
}
