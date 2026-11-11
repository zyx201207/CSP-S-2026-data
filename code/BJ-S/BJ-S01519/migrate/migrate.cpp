#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define endl '\n'
int c;
const int N=2e6+10;
int x[N],dis[N],g[N],pre[N],rps[N];
void solve(){
    int n,d;
    cin >> n >> d;
    fr(i,1,n)cin >> x[i];
    if(c<=10){
        fr(i,1,n){
            rps[i]=rps[i-1];
            while(rps[i]+1<=n&&x[rps[i]+1]-x[i]<=d)rps[i]++;
        }
        int ans=0;
        fr(r,1,n){
            dis[r]=0,g[r]=1;
            dfr(l,r-1,1){
                int nx=min(r,rps[l]);
                if(nx==l)break;
                g[l]=g[nx];
                int mst=dis[nx];
                while(g[l]<=2&&nx-1>l){
                    nx--;
                    if(dis[nx]>mst)break;
                    g[l]+=g[nx];
                }
                if(g[l]==2)ans++;
                dis[l]=mst+1;
            }
        }
        cout << ans << endl;
    }
    else if(c<=12){
        fr(i,1,n){
            rps[i]=rps[i-1];
            while(rps[i]+1<=n&&x[rps[i]+1]-x[i]<=d)rps[i]++;
        }
        int len=rps[1];
       // cout << n << " " << len << " ";
        if(len>=3)
            cout << max(0LL,n-2*len+3) << endl;
        else cout << 0 << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;

    cin >> c >> t;
    while(t--)solve();
    return 0;
}
