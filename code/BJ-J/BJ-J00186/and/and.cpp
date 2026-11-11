#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > a(200200, vector <int> (32, 0));
vector <int> b(32, -1);
int n, m, ans = 0, t;

void dfs(vector <int> had, int where){
    for (int i = where; i >= 0; i--){
        int sum = 0;
        vector <int> have;

        for (int j = 0; j < had.size(); j++){
            if (a[had[j]][i]){
                sum++;
                have.push_back(had[j]);
            }
        }

        if (sum >= m){
            ans += b[i];
            dfs(have, i - 1);
            break;
        }
    }

    return;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> t;
        int j = 0;

        while (t){
            a[i][j++] = t % 2;
            t /= 2;
        }
    }

    for (int i = 0, j = 1; i < 31; i++){
        b[i] = j;
        j *= 2;
    }

    for (int i = 30; i >= 0; i--){
        int sum = 0;
        vector <int> have;

        for (int j = 0; j < n; j++){
            if (a[j][i]){
                sum++;
                have.push_back(j);
            }
        }

        if (sum >= m){
            ans += b[i];
            dfs(have, i - 1);
            break;
        }
    }

    cout << ans;
    return 0;
}
