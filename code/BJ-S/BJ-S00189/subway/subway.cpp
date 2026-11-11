#define NDEBUG

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

#define SELF (*this)

using ULL = unsigned long long;

ULL reMin(ULL& a, ULL b) {
    return a = min(a, b);
}

struct Step {
    size_t p;
    ULL v;
};

bool operator<(const Step& a, const Step& b) {
    return a.v < b.v;
}

bool operator>(const Step& a, const Step& b) {
    return a.v > b.v;
}

struct Graph;
#ifndef NDEBUG
    ostream& operator<<(ostream& stm, const Graph& g);
#endif

struct Graph {
    vector<map<size_t, ULL>> e;
    Graph(size_t n) : e(n) {}
    Graph& addEdge(size_t a, size_t b, ULL v) {
        if (!e[a].count(b) || e[a][b]<v) {
            e[a][b] = e[b][a] = v;
        }
        return SELF;
    }
    auto simp0(size_t n) const {
        vector<vector<ULL>> res(n, vector<ULL>(n, -1));
        for (size_t i=0; i<n; ++i) {
            //cerr << "i: " << i << "\n";
            priority_queue<Step, vector<Step>, greater<Step>> q; q.push({i, 0});
            vector<bool> vis(e.size(), 0);
            while (!q.empty()) {
                const size_t p = q.top().p;
                const ULL v = q.top().v;
                q.pop();
                //cerr << "p: " << p << "\n";
                if (vis[p]) {
                    continue;
                }
                vis[p] = 1;
                for (const auto pr : e[p]) {
                    if (vis[pr.first]) {
                        continue;
                    }
                    q.push({pr.first, v+pr.second});
                }
                if (p < n){
                    assert(!~res[i][p]);
                    res[i][p] = v;
                }
            }
        }
        #ifndef NDEBUG
            for (const auto& i : res) {
                for (const auto& j : i) {
                    assert(~j);
                }
            }
        #endif
        return res;
    }
    auto simp(size_t n) const {
        Graph sg(n);
        for (size_t i=0; i<n; ++i) {
            for (const auto pr0 : e[i]) {
                for (const auto pr1 : e[pr0.first]) {
                    if (pr1.first < n) {
                        sg.addEdge(i, pr1.first, pr0.second+pr1.second);
                    }
                }
            }
        }
        vector<vector<ULL>> res(n, vector<ULL>(n, -1));
        for (size_t i=0; i<n; ++i) {
            //cerr << "i: " << i << "\n";
            priority_queue<Step, vector<Step>, greater<Step>> q; q.push({i, 0});
            vector<bool> vis(n, 0);
            while (!q.empty()) {
                const size_t p = q.top().p;
                const ULL v = q.top().v;
                q.pop();
                //cerr << "p: " << p << "\n";
                if (vis[p]) {
                    continue;
                }
                vis[p] = 1;
                for (const auto pr : sg.e[p]) {
                    if (vis[pr.first]) {
                        continue;
                    }
                    q.push({pr.first, v+pr.second});
                }
                assert(!~res[i][p]);
                res[i][p] = v;
            }
        }
        return res;
    }
};
#ifndef NDEBUG
    ostream& operator<<(ostream& stm, const Graph& g) {
        for (size_t i=0; i<g.e.size(); ++i) {
            stm << i << ": ";
            for (const auto pr : g.e[i]) {
                stm << pr.first << " " << pr.second << "; ";
            }
            stm << "\n";
        }
        return stm;
    }
    ostream& operator<<(ostream& stm, const vector<ULL>& v) {
        for (const auto i : v) {
            stm << i << " ";
        }
        return stm;
    }
    ostream& operator<<(ostream& stm, const vector<vector<ULL>>& v) {
        for (const auto i : v) {
            stm << i << "\n";
        }
        return stm;
    }
#endif

ULL solve(const Graph& g0, const vector<vector<ULL>>& g1, size_t x, size_t y) {
    ULL res=-1;
    for (const auto a : g0.e[x+g1.size()]) {
        for (const auto b : g0.e[y+g1.size()]) {
            const auto i=a.first, j=b.first;
            if (i>g1.size() || j>g1.size()) {
                continue;
            }
            reMin(res, a.second + b.second + g1[i][j]);
        }
    }
    return res;
}

int main() {
    #ifdef NDEBUG
        ios::sync_with_stdio(0);
    #endif
    ifstream fin("subway.in");
    ofstream fout("subway.out");
    size_t c, n, m, d, q; fin >> c >> n >> m >> d >> q;
    vector<ULL> w(m);
    for (auto& i : w){
        fin >> i;
    }
    Graph g0(n+m);
    for (size_t i=0; i<n; ++i) {
        size_t k; fin >> k;
        for (size_t j=0; j<k; ++j) {
            size_t a; ULL t; fin >> a >> t; --a;
            g0.addEdge(i, a+n, t);
        }
    }
    const auto g1 = g0.simp(n);
    //cerr << g0 << "\n" << g1 << "\n";
    for (size_t r=0; r<q; ++r) {
        size_t x, y; fin >> x >> y; --x; --y;
        fout << (solve(g0, g1, x, y) + w[x] + w[y]) << "\n";
    }
    return 0;
}
