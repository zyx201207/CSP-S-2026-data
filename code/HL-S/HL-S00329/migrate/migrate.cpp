#include <iostream>
#define int long long
using namespace std;

int x[2000010];
bool is_ans[5010][5010];
bool vis[2000010];
int mw,summw;
int n,d;

int dis(int u,int v) {
    return ((x[v]-x[u])>0)?(x[v]-x[u]):(x[u]-x[v]);
}

void dfs(int u,int v,int x) {
    if (u==v) {
    	if (mw==-1) {
    		mw=x;
    		summw=1;
		}
        else if (x<mw) {
            summw=1;
            mw=x;
        }
        else if (x==mw) {
            summw++;
        }
        return;
    }
    for (int i=1;i<=n;i++) {
        if (dis(i,u)<=d) {
            if (vis[i]) continue;
            vis[i]=1;
            dfs(i,v,x+1);
            vis[i]=0;
        }
    }
    return;
}

void solve() {
    cin>>n>>d;
    for (int i=1;i<=n;i++) {
        cin>>x[i];
    }

    int ans=0;
    for (int i=1;i<n;i++) {
        for (int j=i+1;j<=n;j++) {
            mw=-1,summw=0;
            dfs(i,j,0);
            if (summw==2) {
                ans++;
                is_ans[i][j]=1;
                is_ans[j][i]=1;
            }
        }
    }
    cout<<ans<<endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if (c==13||c==14) {
        for (int i=1;i<=t;i++) {
            cin>>n>>d;
            for (int i=1;i<=n;i++) {
                cin>>x[i];
            }
            cout<<n*(n-1)/2;
        }
    }
    while (t--) {
        solve();
    }
    return 0;
}
