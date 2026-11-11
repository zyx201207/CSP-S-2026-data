#include <bits/stdc++.h>
using namespace std;
const int maxm = 5e5 + 5;
const int maxk = 1e3 + 5;
const int maxn = 5e2 + 5;
int c,n,m,d,q,w[maxm];
int a[maxn][maxk],t[maxn][maxk],k[maxn],ans;
int s[maxk][maxn],l[25];
int v[maxm];

void dfs(int y,int now,int time,bool f,int r){
    if(now == y){
        //cout << ' ' << now << ' ' << time + w[now] << ' ' << time << ' ' << ans << endl;
        ans = min(ans,time + w[now]);
        return ;
    }
    if(f == true){
        for(int i = 1;i <= l[now];i++){
            int ii = s[now][l[i]];
            if(ii == r)continue;
            for(int j = 1;j <= k[ii];j++){
                if(a[ii][j] == now){
                    //cout << now << ' ' << ii << ' ' << l[i] << ' ' << s[now][l[i]] << ' ' << a[ii][j] << ' ' << t[ii][j] << endl;
                    dfs(y,now,time + t[ii][j],false,s[now][l[i]]);
                    break;
                }
            }
        }
        return ;
    }
    int i = r;
    //cout << now << ' ' << i << ' ' << k[i] << endl;
    for(int j = 1;j <= k[i];j++){
        if(a[i][j] == now)continue;
        if(v[a[i][j]] <= time + t[i][j])continue;
        //if(l[a[i][j]] == 1)continue;
        //cout << now << ' ' << a[i][j] << ' ' << time + t[i][j] << ' ' << i << ' ' << j << ' ' << t[i][j] << ' ' << v[a[i][j]] << endl;
        dfs(y,a[i][j],time + t[i][j],true,r);
        v[a[i][j]] = time + a[i][j];
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","r",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++){
            cin >> a[i][j] >> t[i][j];
            int r = a[i][j];
            s[r][++l[r]] = i;
        }
    }
    /*
    cout << endl;
    for(int i = 1;i <= m;i++){
        for(int z = 1;z <= l[i];z++){
            cout << s[i][l[z]] << ' ';
        }
        cout << endl;
    }
    */

    int x,y;
    while(q--){
        cin >> x >> y;
        for(int i = 1;i <= m;i++){
            v[i] = 1e9;
        }
        ans = 1e9;
        dfs(y,x,w[x],true,0);
        cout << ans << endl;
    }
    return 0;
}
