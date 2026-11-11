#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1005;
const int N=505;
//const int Q=1e5+5;
const int K=5005;
int c,n,m,d,q;
int w[M];
int k[N];
//int a[N][K];
int t[N][K];
set<pair<int,int>> sta[M];
int ans=0x3f3f3f3f;
int st,ed;
bool vis[N];
int sum;
int tong[N][M];
void dfs(int x,int line){
    if(x==ed){
        //cout << ans << " " << sum << endl;
        ans=min(ans,sum);
        return ;
    }
    //cout << x << ":\n";
    for(auto i:sta[x]){
        if(!vis[i.second]){
            //cout << i.second << ":\n";
            vis[i.second]=1;
            //cout << i.first << " " << i.second << " " << sum << " ";
            sum+=t[i.first][x];
            if(line!=i.first){
                sum+=t[i.first][i.second];
            }
            //cout << t[i.first][i.second] << endl;
            dfs(i.second,i.first);
            vis[i.second]=0;
            sum-=t[i.first][x];
            if(line!=i.first){
                sum-=t[i.first][i.second];
            }
        }
    }
    return ;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        int x,y,tt;
        cin >> x >> t[i][x];
        y=x;
        tong[i][x]=1;
        for(int j=2;j<=k[i];j++){
            cin >> x >> t[i][x];
            tong[i][x]=1;
            sta[y].insert({i,x});
            sta[x].insert({i,y});
            y=x;
        }
    }
    //cout << "station:\n\n";
    for(int i=1;i<=m;i++){
        //cout << i << ":";
        for(auto x:sta[i]){
            //cout << x.first << " " << x.second << endl;
        }
        //cout << endl;
    }
    //cout << "times:\n\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //cout << t[i][j] << " ";
        }
        //cout << endl;
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        int x,y;
        cin >> x >> y;
        st=x;
        ed=y;
        vis[st]=1;
        dfs(st,0);
        ans+=(w[x]+w[y]);
        cout << ans << endl;
        ans=0x3f3f3f3f;
    }
    return 0;
}
