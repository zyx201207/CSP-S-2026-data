
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int bck[500005];
int ans[500005];
vector <int> v[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int A = 1;
    for (int i = 1; i <= n; i++) cin >> a[i],A &= (a[i]>= a[i-1]);
    for (int i = 1; i <= n; i++)
        bck[a[i]] = i;
    if (A){
        for (int i = 1; i <= n; i++) ans[a[i]]++;
        for (int i = 1; i <= m; i++) ans[i] += ans[i-1],cout << ans[i] << " ";
        return 0;
    }
        int time = 0;
    for (int i = 1; i <= n; i++){
        int start = i;
        while (start <= n){
            v[i].push_back(a[start]);
            start = bck[a[start]];
            start ++;
        }
        for (int j =0; j < v[i].size(); j++) ans[v[i][j]] ++;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] <<" ";
    return 0;
}
