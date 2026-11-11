#include <bits/stdc++.h>

using namespace std;

int c, T;

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> T;

    for (int abc = 0; abc < T; abc++){
        vector <vector <int> > a(100100, vector <int> ());
        int n, k, u, v, MAX = 0;
        cin >> n >> k;

        for (int i = 1; i < n; i++){
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

        for (int i = 1; i < n; i++){
            if (a[i].size() == 1){
                vector <int> went(100100, 0);
                queue <pair <int, int> > q;
                went[i]++;
                q.push({i, 1});

                while (q.size()){
                    pair <int, int> t = q.front();
                    q.pop();

                    for (int j = 0; j < a[t.first].size(); j++){
                        if (!went[a[t.first][j]]++){
                            q.push({a[t.first][j], t.second + 1});
                            MAX = max(MAX, t.second + 1);
                            cout << k;
                        }
                    }
                }
            }
        }

        if (k >= MAX){
            cout << 0 << "\n";
        }
        else if (k == 1){
            cout <<(MAX - k + 1)/ 2 << "\n";
        }
        else {
            cout <<(MAX - k + 2)/ 3 << "\n";
        }
    }

    return 0;
}
