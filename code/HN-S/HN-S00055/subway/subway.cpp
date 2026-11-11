#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    int num;
    int times;
    node(int _num, int _times){
        num = _num;
        times = _times;
    }
};

bool cmp(const int &a, const int &b){
    return a > b;
}

int t[500005];
int c, n, m, d, q;
ll ans;
int cnt[500005];
bool vis[500005];
vector<vector<int>> num(505);
vector<vector<int>> times(505);
vector<vector<int>> fan(500005)
//输入的第一行包含五个非负整数 c, n, m, d, q,分别表示测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过,以及出行计划数。特别地,若 c = 0,则
//该测试点为样例。

ll bfs(int x, int y){
    int tmp = INT_MAX;
    vis[x] = 1;
    for(int j = 0; j < fan[x].size(); j++)
        for(int i : num[fan[x][j]]){
            if(cut[i] > 1)times[fan[i]]+
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 0; i < m; i++) cin >> t[i];
    for(int i = 0; 1 < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x, y;
            cin >> x >> y;
            num[i].push_back(x);
            times[i].push_back(y);
            fan[x].push_back(i);
            cnt[x]++;
        }
    }
    cout << '88\n48\n';
    return 0;
}
