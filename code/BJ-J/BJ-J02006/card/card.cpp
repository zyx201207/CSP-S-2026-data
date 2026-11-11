#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 5e5+5;
const int N = 3e5+5;
int n,m,a[M],vis[N],pos[N],cnt[N];
void solve(int x){
    memset(vis,0,sizeof(vis));
    memset(pos,-1,sizeof(pos));
    stack <int> s;
    for (int i = x;i <= n;i++){
        int k = a[i];
        if (vis[k]){
            int kpos = pos[k]+1;
            for (int j = kpos;j <= s.size()+kpos;j++){
                vis[s.top()] = 0;
                pos[s.top()] = -1;
                s.pop();
            }

        }
        s.push(k);
        pos[k] = s.size();
        vis[k] = 1;
    }
    while (!s.empty()){
        cnt[s.top()]++;
        s.pop();
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for (int t = 1;t <= n;t++){
        solve(t);
    }
    for (int i = 1;i <= m;i++){
        cout << cnt[i] << ' ';
    }
    return 0;
}
