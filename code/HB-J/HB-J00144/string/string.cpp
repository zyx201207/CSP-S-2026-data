#include <bits/stdc++.h>
using namespace std;
void open (string s) {
    string in = s + ".in", out = s + ".out";
    freopen (in.c_str(), "r", stdin);
    freopen (out.c_str(), "w", stdout);
}
typedef long long ll;
struct node {
    ll fst, ed;
    char val;
} q[1000100], pre[1000100], bck[1000100];
int n;
ll len;
int main () {
    open ("string");
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ll tlen;
        cin >> tlen >> q[i].val;
        q[i].fst = q[i - 1].ed + 1;
        q[i].ed = q[i].fst + tlen - 1;
        len += tlen;
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << q[i].val << "-> begin:" << q[i].fst << " | end:" << q[i].ed << " |\n";
    // }
    ll ppre = 0, pbck = 0;
    if (len % 2 == 0) {
        ll mid = len / 2;
        for (int i = 1; i <= n; ++i) {
            if (mid >= q[i].ed) {
                pre[++ppre] = q[i];
            } else if (mid < q[i].fst) {
                bck[++pbck] = q[i];
            } else {
                node px, bx;
                px = {q[i].fst, mid, q[i].val};
                bx = {mid + 1, q[i].ed, q[i].val};
                pre[++ppre] = px, bck[++pbck] = bx;
            }
        }
    } else if (len % 2 == 1) {
        ll mid = (len + 1) / 2;
        for (int i = 1; i <= n; ++i) {
            if (mid > q[i].ed) {
                pre[++ppre] = q[i];
            } else if (mid < q[i].fst) {
                bck[++pbck] = q[i];
            } else {
                node px, bx;
                px = {q[i].fst, mid - 1, q[i].val};
                bx = {mid + 1, q[i].ed, q[i].val};
                if (px.fst <= px.ed)
                   pre[++ppre] = px;
                if (bx.fst <= bx.ed)
                   bck[++pbck] = bx;
            }
        }
        
    }
    for (int i = 1; i <= pbck; ++i) {
        bck[i].fst = len - bck[i].fst + 1;
        bck[i].ed = len - bck[i].ed + 1;
        swap(bck[i].fst, bck[i].ed);
    }
    sort(bck + 1, bck + pbck + 1, [](node x, node y) {
        if (x.fst == y.fst) return x.ed < y.ed;
        return x.fst < y.fst;
    });
    ll ans, t1 = 1, t2 = 1;
    ans = len / 2;
    while (t1 <= pbck and t2 <= pbck) {
        node p = pre[t1], b = bck[t2];
        // cout << p.fst << " " << p.ed << " " << p.val << endl;
        // cout << b.fst << " " << b.ed << " " << b.val << endl;
        // cout << "==========" << endl;
        if (p.fst == b.fst) {
            if (p.ed == b.ed) {
                if (p.val == b.val) 
                    ans -= p.ed - p.fst + 1;
                t1++, t2++;
            } else if (p.ed > b.ed) {
                if (p.val == b.val) 
                    ans -= b.ed - b.fst + 1;
                t2++;
            } else {
                if (p.val == b.val)
                    ans -= p.ed - p.fst + 1;
                t1++;
            }
        } else if (p.fst < b.fst) {
            if (p.ed == b.ed) {
                if (p.val == b.val)
                    ans -= p.ed - b.fst + 1;
                t1++, t2++;
            } else if (p.ed < b.ed){
                if (p.val == b.val) 
                    ans -= p.ed - b.fst + 1;
                t1++;
            } else {
                if (p.val == b.val) 
                    ans -= b.ed - b.fst + 1;
                t2++;
            }
        } else {
            if (p.ed == b.ed) {
                if (p.val == b.val) 
                    ans -= b.ed - p.fst + 1;
                t1++, t2++;
            } else if (p.ed < b.ed) {
                if (p.val == b.val) 
                    ans -= p.ed - p.fst + 1;
                t1++;
            } else {
                if (p.val == b.val) 
                    ans -= b.ed - p.fst + 1;
                t2++;
            }
        }
    }
    cout << ans << endl;
    // cout << "pre:\n";
    // for (int i = 1; i <= ppre; ++i) {
    //     cout << pre[i].val << "-> begin:" << pre[i].fst << " | end:" << pre[i].ed << " |\n";
    // }
    // cout << "bck:\n";
    // for (int i = 1; i <= pbck; ++i) {
    //     cout << bck[i].val << "-> begin:" << bck[i].fst << " | end:" << bck[i].ed << " |\n";
    // }
    return 0;
}
