#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans,f;char c;
inline ll read(){
    ans = 0;f = 1;char c;
    c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ans = 10*ans + c-'0';
        c = getchar();
    }
    return ans*f;
}
struct node{
    ll p,v;

    bool operator <(const node &tmp) const{
        return v > tmp.v;
    }
};
ll cc,m,n,d,q,l,r,k,a,t,p,v,res,w[500005];
vector<node> lis[500005],tlis[505];
ll dis[505][505];
ll sig[505],rou,minn[505];
priority_queue<node> pq;

void dij(int beg){
    rou++;sig[beg] = rou;
    pq.push({beg,0});minn[beg] = 0;

    while(pq.size()){
        p = pq.top().p;v = pq.top().v;
        pq.pop();

        if(minn[p] != v) continue;
        for(node it : tlis[p]){
            if(sig[it.p] != rou){
                sig[it.p] = rou;
                minn[it.p] = LLONG_MAX;
            }

            if(minn[it.p] > minn[p] + it.v){
                minn[it.p] = minn[p] + it.v;
                pq.push({it.p,minn[it.p]});
            }
        }
    }

    for(int i = 1;i <= n;i++){
        dis[beg][i] = min(dis[beg][i],minn[i]);
        dis[i][beg] = dis[beg][i];
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cc = read();n = read();m = read();
    d = read();q = read();
    for(int i = 1;i <= m;i++) w[i] = read();
    for(int i = 1;i <= n;i++){
        k = read();
        for(int j = 1;j <= k;j++){
            a = read();t = read();
            lis[a].push_back({m+i,t});
        }
    }

    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < lis[i].size();j++){
            for(int k = 0;k < j;k++){
                dis[lis[i][j].p-m][lis[i][k].p-m] = min(dis[lis[i][j].p-m][lis[i][k].p-m],lis[i][k].v+lis[i][j].v);
                dis[lis[i][k].p-m][lis[i][j].p-m] = dis[lis[i][j].p-m][lis[i][k].p-m];
            }
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = i+1;j <= n;j++){
            if(dis[i][j] != dis[0][0]){
                tlis[i].push_back({j,dis[i][j]});
                tlis[j].push_back({i,dis[i][j]});
            }
        }
    }

    for(int i = 1;i <= n;i++) dij(i);

    while(q--){
        l = read();r = read();

        res = LLONG_MAX;
        for(int i = 0;i < lis[l].size();i++){
            for(int j = 0;j < lis[r].size();j++){
                res = min(res,lis[l][i].v + lis[r][j].v + dis[lis[l][i].p-m][lis[r][j].p-m]);
            }
        }

        cout << res+w[l]+w[r] << '\n';

    }


    fclose(stdin);fclose(stdout);
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
