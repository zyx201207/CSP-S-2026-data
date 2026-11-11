#include<cstdio>
#include<iostream>
using namespace std;

struct node {
    int a;
    char c;
    long long l, r;
} p1[200005], p2[200005], np1[400005], np2[400005];

int n, mapi, len;
long long cnt;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p1[i].a >> p1[i].c;
        p1[i].l = p1[i - 1].r + 1;
        p1[i].r = p1[i - 1].r + p1[i].a;

    }
    for (int i = 1; i <= n; i++) {
        p2[i].a = p1[n - i + 1].a;
        p2[i].c = p1[n - i + 1].c;
        p2[i].l = p1[n - i + 1].l;
        p2[i].r = p1[n - i + 1].r;
    }
    np1[0].l = -1;
    np1[0].r = -1;
    for (int i = 1, p1p = 0, p2p = 0; ; i++) {
        if (p1[p1p].a < p2[p2p].a) {
            mapi = 1;
            p2[p2p].a -= p1[p1p].a;
            p2[p2p].r -= p1[p1p++].a;
        } else if (p1[p1p].a > p2[p2p].a) {
            mapi = 2;
            p1[p1p].a -= p2[p2p].a;
            p1[p1p].l += p2[p2p++].a;
        } else {
            mapi = 0;
            p1p++;
            p2p++;
        }
        np1[i].c = p1[p1p].c;
        np1[i].l = p1[p1p].l;
        np1[i].r = p1[p1p].r;
        np2[i].c = p2[p2p].c;
        np2[i].l = p2[p2p].l;
        np2[i].r = p2[p2p].r;
        if (mapi == 1) {
            np2[i - 1].l = np2[i].r + 1;
            np2[i - 1].a = np2[i - 1].r - np2[i - 1].l + 1;
        } else if (mapi == 2) {
            np1[i - 1].r = np1[i].l - 1;
            np1[i - 1].a = np1[i - 1].r - np1[i - 1].l + 1;
        }
        np1[i].a = np1[i].r - np1[i].l + 1;
        np2[i].a = np2[i].r - np2[i].l + 1;
        if (np1[i - 1].l == np2[i - 1].l && np1[i - 1].r == np2[i - 1].r) {
            len = i - 1;
            break;
        }
    }
    for (int i = 1; i < len; i++) {
        if (np1[i].c != np2[i].c) {
            cnt += np1[i].a;
        }
    }
    cout << cnt;

    return 0;
}
