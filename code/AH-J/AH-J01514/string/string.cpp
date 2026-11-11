#include<bits/stdc++.h>
using namespace std;
struct Node {
    long long cnt;
    char ch;
};

int main() 
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    vector<Node> seg(n);
    for (int i = 0; i < n; ++i) {
        cin >> seg[i].cnt >> seg[i].ch;
    }
    int l = 0, r = n - 1;
    long long leftRem = seg[l].cnt;
    long long rightRem = seg[r].cnt;
    long long ans = 0;

    while (l < r) {
        long long take = min(leftRem, rightRem);
        if (seg[l].ch != seg[r].ch) {
            ans += take;
        }
        leftRem -= take;
        rightRem -= take;
        if (leftRem == 0) {
            l++;
            if (l < r) leftRem = seg[l].cnt;
        }
        if (rightRem == 0) {
            r--;
            if (l < r) rightRem = seg[r].cnt;
        }
    }
    cout << ans << endl;
    return 0;
}
