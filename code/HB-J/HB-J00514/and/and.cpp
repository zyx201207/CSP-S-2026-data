#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, ans;
ll a;
map<int, int> mp;

struct Element {
    int val;
    int ind;
};

bool cmp(Element e1, Element e2) {
    return e1.val > e2.val;
}

vector<Element> v;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        while (a != 0) {
            mp[(ll)log2(a & (-a))]++;
            a -= (a & (-a));
        }
    }
    for (int i = 0; i <= 4000; i++) {
        v.push_back((Element){mp[i], i});
    }
    sort(v.begin(), v.end(), cmp);
    int cnt_chose = 0;
    for (Element e : v) {
        if (cnt_chose == m) {
            break;
        }
        ans += (1 << e.ind);
        cnt_chose++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}