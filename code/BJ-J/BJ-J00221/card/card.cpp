#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500005];
bool t[500005];
int ans[500005];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    for (int i=1; i<=n; i++){
        memset(t, 0, sizeof(t));
        stack <int> s;
        for (int j=i; j<=n; j++){
            if (t[a[j]]){
                while (s.top() != a[j]){
                    t[s.top()] = 0;
                    s.pop();
                }
            }
            else {
                t[a[j]] = 1;
                s.push(a[j]);
            }
        }
        for (int j=1; j<=m; j++){
            ans[j] += t[j];
        }
    }
    for (int i=1; i<=m; i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;

    return 0;
}
