#include<bits/stdc++.h>
using namespace std;
const int M = 2e6 + 10;
int n, c, t, d, x[M], a, b, cnt, minn;
bool vis[M];
vector<pair<int, int> > vivi, yes, no;
void dfs(int st, int en, int step){
    if(step >= minn) return;
    if(st = en){
        minn = min(minn, step);
        return;
    }
    vis[st] = true;
    for(int i = 0; i < vivi.size(); i++){
        if(vis[i]){
            dfs(vivi[i].second, en, step + 1);
        }
    }vis[st] = false;
}
void bfs(int st, int en, int step, int start){
    if(step > minn) return;
    if(st = en){
        int flag = false;
        for(int i = 0; i < no.size(); i++)
            if(no[i].first == st && no[i].second == en || no[i].first == en && no[i].second == st)
                flag = true;
                cnt--;
        if(!flag){
            for(int i = 0; i < yes.size(); i++){
                if(yes[i].first == st && yes[i].second == en || yes[i].first == en && yes[i].second == st){
                    cnt++;
                    no.push_back({yes[i].first, yes[i].second});
                    no.push_back({yes[i].second, yes[i].first});
                    yes[i].first = -1;
                    flag = true;
                }
            }
            if(!flag){
                yes.push_back({st , en});
                yes.push_back({en , st});
            }
        }
        return;
    }vis[st] = true;
    for(int i = 0; i < vivi.size(); i++){
        if(vivi[i].first = st && ! vis[i]){
            bfs(vivi[i].second, en, step + 1, start);
        }
    }vis[st] = false;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    for(int z = 0; z < t; z++){
            cin >> n >> d;
        for(int i = 0; i < n; i++){
            cin >> x[M];
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(x[j] - x[i] <= d){
                    vivi.push_back({i, j});
                    vivi.push_back({j, i});
                }
            }
        }
        for(int i = 0; i < n; i++){
                cnt = 0;
                minn = 0x3f3f3f3f;
            for(int j = i; j < n; j++){
            dfs(i, j, 0);
            bfs(i ,j ,0 ,i);
            }
            cout << cnt;
        }
    }
    return 0;
}
