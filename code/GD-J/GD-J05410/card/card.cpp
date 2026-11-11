#include <iostream>
#include <vector>
using namespace std;

const int N = 5 * 1e5 + 1, M = 3 * 1e5 + 1;
int cards[N];
vector<int> cs, mid[N];
bool has[M][N];

int main() {
    freopen("card1.in", "r", stdin);
    freopen("card.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> cards[i];

    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            int c = cards[i];
            if(has[c]) {
                for(int k = 0; k < mid[c].size(); ++k)
                    has[k][mid[c][k]] = false;
                mid[c].clear();
            } if(!cs.empty())
                for(int k = 0; k < cs.size(); ++k)
                    mid[cs[k]].push_back(c);
            cs.push_back(c);
            has[i][c] = true;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= m; ++j)
            if(has[i][j]) ++cnt;
        cout << cnt << ' ';
    }
    cout << endl;
    return 0;
}
