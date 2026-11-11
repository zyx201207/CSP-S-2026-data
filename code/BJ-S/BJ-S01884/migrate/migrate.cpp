#include <bits/stdc++.h>

#define FI
#define FO

int main() {
#define int long long
    constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#ifdef FI
    std::ifstream fin("migrate.in");
#else
#define fin std::cin
#endif
#ifdef FO
    std::ofstream fout("migrate.out");
#else
#define fout std::cout
#endif
    int c, t;
    fin >> c >> t;
    while (t--) {
        int n, d;
        fin >> n >> d;
        std::vector<int> x(n + 1);
        for (int i = 1; i <= n; ++i) {
            fin >> x.at(i);
        }
        if (n <= 3) {
            fout << 0 << "\n";
            continue;
        }
        std::vector<int> right(n + 1);
        for (int i = 1; i <= n; ++i) {
            int l = i, r = n;
            int ans = i;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (x.at(mid) - x.at(i) <= d) {
                    l = mid + 1;
                    ans = mid;
                } else {
                    r = mid - 1;
                }
            }
            right.at(i) = ans;
        }
        // for (int i = 1; i <= n; ++i) {
        //     fout << left.at(i) << " " << right.at(i) << "\n";
        // }
        if (c <= 6) {
            auto bfs = [&](int s) {
                std::vector<int> cnt(n + 1);
                std::vector<int> dis(n + 1, -1);
                cnt.at(s) = 1;
                dis.at(s) = 0;
                std::queue<int> que;
                que.push(s);
                while (!que.empty()) {
                    int u = que.front();
                    que.pop();
                    for (int i = u + 1; i <= right.at(u); ++i) {
                        if (dis.at(i) == -1) {
                            dis.at(i) = dis.at(u) + 1;
                            cnt.at(i) = cnt.at(u);
                            que.push(i);
                        } else if (dis.at(i) == dis.at(u) + 1) {
                            cnt.at(i) += cnt.at(u);
                        }
                    }
                }
                int res = 0;
                // fout << s << ": ";
                for (int i = s + 1; i <= n; ++i) {
                    if (cnt.at(i) == 2) {
                        ++res;
                        // fout << s << " " << i << "\n";
                    }
                    // fout << dis.at(i) << " ";
                }
                // fout << "\n";
                return res;
            };
            int ans = 0;
            for (int i = 1; i <= n; ++i) {
                ans += bfs(i);
            }
            fout << ans << "\n";
            continue;
        }
        if (c <= 10) {
            struct Edge {
                int to, next, len;
            };
            std::vector<Edge> edge;
            std::vector<int> h;
            auto addEdge = [&](int x, int y, int len) {
                if (h.size() <= x) {
                    h.resize(x + 1, -1);
                }
                if (h.size() <= y) {
                    h.resize(y + 1, -1);
                }
                //std::cout << x << " " << y << " " << len << "\n";
                edge.push_back({y, h.at(x), len});
                h.at(x) = static_cast<int>(edge.size()) - 1;
            };
            struct node {
                int L{-1}, R{-1};
                int ls{-1}, rs{-1};
            };
            std::vector<node> st{{}, {}};
            auto make = [&] {
                int res = static_cast<int>(st.size());
                st.emplace_back();
                return res;
            };
            auto pushdown = [&](int rt) {
                if (st.at(rt).ls == -1) {
                    int tmp = make();
                    st.at(rt).ls = tmp;
                }
                if (st.at(rt).rs == -1) {
                    int tmp = make();
                    st.at(rt).rs = tmp;
                }
            };
            std::vector<int> id(n + 1);
            std::function<void(int, int, int)> build = [&](int rt, int l, int r) {
                st.at(rt).L = l;
                st.at(rt).R = r;
                if (l == r) {
                    id.at(l) = rt;
                    return;
                }
                pushdown(rt);
                int mid = (l + r) >> 1;
                addEdge(rt, st.at(rt).ls, 0);
                addEdge(rt, st.at(rt).rs, 0);
                build(st.at(rt).ls, l, mid);
                build(st.at(rt).rs, mid + 1, r);
            };
            std::function<void(int, int, int, int, int, int)> connect = [&](int x, int L, int R, int rt, int l, int r) {
                if (L <= l && r <= R) {
                    addEdge(id.at(x), rt, 1);
                    addEdge(rt, id.at(x), 1);
                    return;
                }
                if (r < L || R < l) {
                    return;
                }
                pushdown(rt);
                int mid = (l + r) >> 1;
                connect(x, L, R, st.at(rt).ls, l, mid);
                connect(x, L, R, st.at(rt).rs, mid + 1, r);
            };
            build(1, 1, n);
            for (int i = 1; i <= n; ++i) {
                connect(i, i + 1, right.at(i), 1, 1, n);
            }
            int tot = static_cast<int>(h.size());
            auto bfs = [&](int s) {
                std::vector<int> cnt(tot + 1);
                std::vector<int> dis(tot + 1, -1);
                int aaa = s;
                s = id.at(s);
                cnt.at(s) = 1;
                dis.at(s) = 0;
                std::deque<int> que;
                que.push_back(s);
                while (!que.empty()) {
                    int u = que.front();
                    que.pop_front();
                    for (int i = h.at(u); i != -1; i = edge.at(i).next) {
                        int to = edge.at(i).to;
                        int len = edge.at(i).len;
                        // std::cout << "from [" << st.at(u).L << ", " << st.at(u).R << "] to [" << st.at(to).L << ", " << st.at(to).R << "] with " << len << "\n";
                        if (dis.at(to) == -1) {
                            dis.at(to) = dis.at(u) + len;
                            cnt.at(to) = cnt.at(u);
                            if (len == 0) {
                                que.push_front(to);
                            } else {
                                que.push_back(to);
                            }
                        } else if (dis.at(to) == dis.at(u) + len) {
                            cnt.at(to) += cnt.at(u);
                        }
                    }
                }
                int res = 0;
                // fout << s << ": ";
                s = aaa;
                for (int i = s + 1; i <= n; ++i) {
                    if (cnt.at(id.at(i)) == 2) {
                        ++res;
                        // fout << s << " " << i << "\n";
                    }
                    // fout << dis.at(i) << " ";
                }
                // fout << "\n";
                return res;
            };
            // fout << id.at(n) << " " << tot << "\n";
            int ans = 0;
            for (int i = 1; i <= n; ++i) {
                ans += bfs(i);
            }
            fout << ans << "\n";
        }
    }
    return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
