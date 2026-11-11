#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6 + 5 , M = 5005 , inf = 0x3f3f3f3f;
int c , T , n;
ll dt , ans;
bool book[N];
ll a[N] , f[M][M] , d[N];
vector < int > e[N];

void bfs (int st) {
    memset(book , 0 , sizeof book);
    memset(d , inf , sizeof d);
    queue < pair < int , int > > q;
    q.push({st , 0});
    book[st] = 1;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        int u = now.first , t = now.second;
        if (d[u] >= inf)
            d[u] = t;
        if (t == d[u])
            f[st][u] ++;
        for (int v : e[u])
            if (t + 1 <= d[v])
                q.push({v , t + 1});
    }
    return ;
}

int main () {
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> c >> T;
    if (c <= 10) {
        while (T --) {
            cin >> n >> dt;
            ans = 0;
            memset(f , 0 , sizeof f);
            for (int i = 1; i <= n; i ++)
                cin >> a[i];
            for (int i = 1; i <= n; i ++)
                e[i].clear();
            for (int i = 2; i <= n; i ++)
                for (int j = 1; j < i; j ++)
                    if (a[i] - a[j] <= dt) {
                        e[i].push_back(j);
                        e[j].push_back(i);
                    }
            for (int i = 1; i <= n; i ++)
                bfs(i);
            for (int i = 1; i <= n; i ++)
                for (int j = i + 1; j <= n; j ++)
                    if (f[i][j] == 2) {
						ans ++;
//						cout << i << ' ' << j << ' ' << f[i][j] << "\n";
					}
            cout << ans << "\n";
        }
    }
    else {
        while (T --) {
            cin >> n >> dt;
            for (int i = 1; i <= n; i ++)
                cin >> a[i];
            
        }
    }
    return 0;
}

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
* 
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

 * */
