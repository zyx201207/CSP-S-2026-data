// 100
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, Res;
int A[N];

struct SegmentTree {
    struct Point { int l, r, tag, val; } tree[N << 2];

    int Len(int pos) { return tree[pos].r - tree[pos].l + 1; }

    void Add_tag(int pos, int K) { tree[pos].tag += K;  tree[pos].val += K * Len(pos); }

    void Push_up(int pos) { tree[pos].val = tree[pos << 1].val + tree[pos << 1 | 1].val; }

    void Push_down(int pos) {
        if(!tree[pos].tag) return;
        Add_tag(pos << 1, tree[pos].tag);  Add_tag(pos << 1 | 1, tree[pos].tag);
        tree[pos].tag = 0;
    }

    void Build(int pos, int L, int R) {
        tree[pos].l = L, tree[pos].r = R, tree[pos].tag = 0;
        if(L == R) { tree[pos].val = A[n] - A[L];  return; }

        int mid = L + R >> 1, Left_son = pos << 1, Right_son = pos << 1 | 1;
        Build(Left_son, L, mid);
        Build(Right_son, mid + 1, R);

        Push_up(pos);
    }

    void Update(int pos, int L, int R, int K) {
        if(R < tree[pos].l || tree[pos].r < L) return;
        if(L <= tree[pos].l && tree[pos].r <= R) { Add_tag(pos, K);  return; }

        Push_down(pos);

        int Left_son = pos << 1, Right_son = pos << 1 | 1;
        Update(Left_son, L, R, K);
        Update(Right_son, L, R, K);

        Push_up(pos);
    }

    int Query(int pos, int L, int R) {
        if(R < tree[pos].l || tree[pos].r < L) return 0;
        if(L <= tree[pos].l && tree[pos].r <= R) return tree[pos].val;

        Push_down(pos);

        int Left_son = pos << 1, Right_son = pos << 1 | 1, res = 0;
        res += Query(Left_son, L, R);
        res += Query(Right_son, L, R);

        return res;
    }

    int Find(int pos, int K) {
        if(tree[pos].l == tree[pos].r) return tree[pos].l;

        Push_down(pos);

        int Left_son = pos << 1, Right_son = pos << 1 | 1;
        if(tree[Left_son].val >= K) return Find(Left_son, K);
        else return Find(Right_son, K - tree[Left_son].val);
    }
} Tree;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  cout.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> A[i];  sort(A + 1, A + n + 1);
    Tree.Build(1, 1, n);
    
    for(int i = n; i >= 1; i--) {
        int Sum = Tree.Query(1, 1, i);
        int pos = (Sum - m > 0) ? Tree.Find(1, Sum - m) + 1 : 1;
        Res = max(Res, i - pos + 1);
        Tree.Update(1, 1, i, A[i - 1] - A[i]);
    }
    cout << Res << '\n';
    return 0;
}