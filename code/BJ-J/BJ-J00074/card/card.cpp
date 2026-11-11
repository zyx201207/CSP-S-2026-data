#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n, m, cnt = 1, ans[10010];
bool vis[10010];
vector<int> a, b, c;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;

    a.push_back(-1);

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }

    for(int i = 1; i <= n; i++){
        for(int j = cnt; j <= n; j++)
            vis[a[j]] = false;

        for(int j = cnt; j <= n; j++){
            if(vis[a[j]]){
                int len = c.size(), sum;
                for(int k = 0; k < len; k++)
                    if(c[k] == a[j])
                        sum = k;
                for(int k = sum; k < len; k++)
                    c.pop_back();
                c.push_back(a[j]);
            }
            else{
                vis[a[j]] = true;
                c.push_back(a[j]);
            }
        }

        cout << endl;
        for(auto j : c)
            ans[j]++;

        for(auto j : c)
            c.pop_back();
        cnt++;
    }

    for(int j = 1; j <= m; j++)
        cout << ans[j] << " ";

    cout << endl;

    return 0;
}