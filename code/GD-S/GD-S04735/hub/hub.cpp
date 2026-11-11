#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4e6 + 5;

int head[N], to[N], nxt[N], tot = 1;
void add(int u, int v) {
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;

    nxt[++tot] = head[v];
    head[v] = tot;
    to[tot] = u;
}

int getSubDep(int fa, int u) {
    int res = 1;
    for (int id = head[u]; id; id = nxt[id]) {
        int v = to[id];
        if (v == fa) continue;
        res += getSubDep(u, v);
    }
    return res;
}

stack<int>* getSubLongest(int fa, int u) {
    stack<int>* res;
    for (int id = head[u]; id; id = nxt[id]) {
        int v = to[id];
        if (v == fa) continue;
        stack<int>* tmp = getSubLongest(u, v);
        printf("@");
        /*
        if(res == nullptr) {
            //res = tmp;
        	continue;
		}*/
        if ((*tmp).size() > (*res).size()) {
        	printf("XXXXXXXX");
            res = tmp;
            delete res;
        }
        printf("@");
    }
    if (res == nullptr) {
        res = new stack<int>;
    }
    (*res).push(u);
    cout << (*res).top() << " ";
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        tot = 1;
        memset(head, 0, sizeof(int) * (n + 5));
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            add(u, v);
        }
        if (n == k) {
            cout << 0 << '\n';
            continue;
        }

        stack<int>*l1, *l2;
        for (int id = head[1]; id; id = nxt[id]) {
            int v = to[id];
            delete l2;
            l2 = l1;
            l1 = getSubLongest(1, v);
        }
        int d = (*l1).size() + (*l2).size();
        cout << d << '\n';


    }



    return 0;
}
