#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

#define lovelive __int128
#if defined(__linux__) || defined(linux) || defined(__linux)
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

//Getting sources is hard sense
//gao(3) fen(1) cai(2) shi(4) ying(4) dao(4) li(1)
//Oh no, I can only input Chinese by Pinyin!
//Yesterday, I had emulated using NOI Linux in the exam, but it seems like that the system has changed, so I can't use VSCode!
//I had taught children that how to use VSCode, I only taught them this!
//I hope they could use other IDE...

using namespace std;

int c, n, m, d, q, k;
const int maxn = 514, maxm = 5*114514;
int w[maxm];
const lovelive lim = 1e30;
struct edge{
    int v, w, next;
};
struct node{
    int id;
    lovelive w;
};
int cnt, head[maxn+maxm], id[maxm];
bool vis[maxn+maxm];
lovelive dis[maxn+maxm];
vector<edge> e;
void add(int u, int v, int w){ //I even don't know that how to guess the limit of the size of the array "e"! so, let's use vector!
    e.push_back({v, w, ++cnt});
    e[cnt].next = head[u];
    head[u] = cnt;
}
bool cmp(const node &a, const node &b){
    return a.w > b.w;
}
void dij(int s){
    for(int i = 1; i <= n+m; ++i){
        dis[i] = lim;
    }
    memset(vis, 0, sizeof vis);
    dis[s] = 0;
    priority_queue<node, vector<node>, decltype(&cmp)> pq(cmp);
    pq.push({s, 0});
    node t;
    int u, v, w;
    while(!pq.empty()){
        t = pq.top();
        pq.pop();
        u = t.id;
        if(vis[u]) continue;
        vis[u] = 1;
        int w = t.w;
        for(int i = head[u]; i; i = e[i].next){
            v = e[i].v, w = e[i].w;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                pq.push({v, dis[v]});
            }
        }
    }
}
int read();
lovelive readll();
void write(lovelive x);

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    e.resize(1);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1; i <= m; ++i){
        w[i] = read();
    }
    int u, v, w_;
    //in the graph, we define that ith railway station in the graph's id = i;
    //for example, the first station's id in the graph is id[1] = 1
    //and, jth line's id is id[j] = j+m;
    //The question requires us that give a begin and a destination, we have to answer that the shortest path's length in the graph
    //We can use Dijkstra, it consts time a lot, but it's a nice idea to get some score
    for(int i = 1; i <= n; ++i){
        k = read();
        id[i] = m+i; //Line i's id in the graph
        for(int j = 1; j <= k; ++j){
            u = m+i;
            v = read(), w_ = read();
            add(u, v, w_);
            add(v, u, w_);
        }
    }
    for(int i = 1; i <= q; ++i){
        scanf("%d%d", &u, &v);
        dij(u);
        write(dis[v]+w[u]+w[v]);
        putchar('\n');
    }
    return 0;
}
//I can only speak input simple sentences, but that's no problem:)
//rp += 114514!


int read(){
    int ans = 0, f = 1;
    char ch = getchar();
    while('0' > ch or ch > '9'){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while('0' <= ch and ch <= '9'){
        ans = ans*10+ch-'0';
        ch = getchar();
    }
    return ans*f;
}
void write(lovelive x){
    if(x == 0){
        putchar('0');
        return;
    }
    if(x < 0){
        x = -x;
        putchar('-');
    }
    static char st[67]; //67676767676767676767676767676767676767676767676767676767676767676767676767676767676767676767676767676767676767676767676767676767676767
    int ptr = 0;
    while(x){
        st[++ptr] = x%10+'0';
        x /= 10;
    }
    while(ptr){
        putchar(st[ptr--]);
    }
}
