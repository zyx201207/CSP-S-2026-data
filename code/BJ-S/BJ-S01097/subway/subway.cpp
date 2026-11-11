#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int C,n,m,D,q;

vector<ll> tout;
vector<vector<pll > > site;// way, time
vector<vector<ll> > edge;// [u,v] = time


void init(){

    tout.resize(m+1);

    site.resize(m+1);

    edge.resize(n);
    for(auto &v:edge){
        v.assign(n, 1e18);
    }

}

void add_edge(int u, int v, ll w){

    if(edge[u][v] > w){
        edge[u][v] = w;
    }
    if(edge[v][u] > w){
        edge[v][u] = w;
    }

}

/*
void add_edge(int u, int v, int w){

    auto &mp = edge[u];
    const auto &it = mp.find(v);
    if(it!=mp.end()){
        if(it->second > w){
            mp[it->first] = w;
        }
    }else{
        mp.insert({v, w});
    }

}*/

void input(){

    for(int i=1;i<=m;i++){
        cin >> tout[i];
    }

    for(int i=0;i<n;i++){

        int len;
        cin >> len;
        for(int j=0;j<len;j++){
            int tsite;
            ll ttime;
            cin >> tsite >> ttime;

            auto &v = site[tsite];
            for(auto p:v){
                add_edge(p.first ,i , p.second + ttime);
            }

            v.push_back({i,ttime});

        }
    }

}

void floyd(){

    for(int mid=0;mid<n;mid++){
        for(int st=0;st<n;st++){
            for(int ed=0;ed<n;ed++){
                edge[st][ed] = min( edge[st][ed], edge[st][mid] + edge[mid][ed] );
            }
        }
    }

    for(int i=0;i<n;i++){
        edge[i][i] = 0;
    }

}


ll get(int s, int e){

    ll ret = 1e18;

    for(auto ps:site[s]){
        for(auto pe:site[e]){
            int ws = ps.first;
            int we = pe.first;
            ll ttrans = ps.second + pe.second;
            ret = min(ret, ttrans + edge[ws][we]);
        }
    }

    return ret;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


    cin >> C >> n >> m >> D >> q;

    init();

    input();

    floyd();

    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << edge[i][j] << ' ';
        }
        cout << endl;
    }*/

    for(int i=0;i<q;i++){
        int s,e;
        cin >> s >> e;
        cout << tout[s] + tout[e] + get(s,e) << endl;
    }

    cout << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
