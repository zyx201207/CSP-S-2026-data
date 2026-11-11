#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, tmp_ans;
bool b[1000005];
struct node {
    vector<int> fa, son;
}a[1000005];
priority_queue<int> ans;
void dfs(int i, int num) {
    tmp_ans = max(num, tmp_ans);
    //cout << i << ' ' << num << '\n';
    if(a[i].son.empty())
        return;
    for(int j=1;j<=a[i].son.size();j++) {
        if(b[i]==false) {
            dfs(a[i].son[j-1], num+1);
            b[i] = true;
        }
    }
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    //freopen("hub.in", "r", stdin);
    //freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        int tmpu, tmpv;
        for(int i=1;i<n;i++) {
            cin >> tmpu >> tmpv;
            a[tmpu].son.push_back(tmpv);
            a[tmpv].fa.push_back(tmpu);
        }
        for(int i=1;i<=n;i++) {
            if(a[i].fa.empty()) {
                tmp_ans = -0x3f3f3f3f;
                //cout << i << ":\n";
                dfs(i, 0);
                //cout << "\n\n";
                ans.push(tmp_ans);
            }
        }
        while(k>=0) {
            tmpu = ans.top();
            //cout << tmpu << ' ';
            tmpu = tmpu%2==0?tmpu/2:tmpu/2+1;
            //cout << tmpu << '\n';
            k--;
            ans.pop();
            ans.push(tmpu);
        }
        cout << ans.top() << '\n';
    }
    return 0;
}
