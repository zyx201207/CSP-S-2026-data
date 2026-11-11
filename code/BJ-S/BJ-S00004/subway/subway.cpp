#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 509,M = 2e4 + 9,D = 49;
ll c,n,m,d,q;
ll w[M];
int a[M][N];//j hao xian i zhan suo xu shi jian
//priority queue
ll dis[N][M];//cheng zuo i hao xian dao j
struct node{
    int pos,line;
};
vector<node> ve[D];
node shuju[M];
node cccccc[M];
int dij(int s,int e){
    priority_queue<pii,vector<pii>,greater<pii>> pq;//dang qian xiao hao i shi jian shu ju bian hao wei j
    int bianhao = 1;

    for(int i = 0;i <= n;i++) for(int j = 1;j <= m;j++) dis[i][j] = 1e18 + 9;
    for(int i = 0;i < ve[s].size();i++){
        pq.push({a[s][ve[s][i].line],i + 1});
        shuju[bianhao++] = {s,ve[s][i].line};
        dis[ve[s][i].line][s] = a[s][ve[s][i].line];
    }
    while(!pq.empty()){
        int shujubianhao = pq.top().second;
        int x = shuju[pq.top().second].pos;
        int pre = shuju[pq.top().second].line;
        int tim = pq.top().first;
        pq.pop();
        //cout << shujubianhao <<" " << x << " " << pre <<" " <<tim << endl;
        bool use = 0;
        for(int i = 0;i < ve[x].size();i++){
            int y = ve[x][i].pos;
            int tm = tim;
            if(pre != ve[x][i].line) tm += (a[x][pre] + a[x][ve[x][i].line]);
            if(dis[ve[x][i].line][y] > tm) {

                dis[ve[x][i].line][y] = tm;
                if(!use){
                    shuju[shujubianhao] = {y,ve[x][i].line};
                    pq.push({tm,shujubianhao});
                    use = 1;
                }
                else{
                    shuju[bianhao++] = {y,ve[x][i].line};
                    pq.push({tm,bianhao - 1});
                }

            }
        }
    }
    ll ans = 1e18;
    for(int i = 1;i <= n;i++) ans = min(ans,dis[i][e] + a[e][i]);
    return ans + w[s] + w[e];
}
void solved(){;
    //dij(1,1);
    //cout << 1 << endl;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >>w[i];
    for(int i = 1;i <= n;i++){
        int x,l;
        cin >> x >> l >> a[l][i];
        for(int j = 2;j <= x;j++){
            int r;
            cin >>r >> a[r][i];
            ve[l].push_back({r,i});
            ve[r].push_back({l,i});
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        //cout << x <<" " << y << endl;
        cout << dij(x,y) << endl;
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solved();
    }
    return 0;
}
