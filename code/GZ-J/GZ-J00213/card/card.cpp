//GZ-J00213遵义市第四中学周高逸

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a[500005], vis[300005], ans[300005];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for(ll i; i<=n; ++i){
        cin >> a[i];
    }

    for(int T=1; T<=n; T++){
        queue<ll> q;
        queue<ll> l;
        memset(vis, 0, sizeof(vis));
        for(ll i; i<=n; ++i){
            q.push(a[i]);
        }
        while(!q.empty()){
            ll c = q.front();
            q.pop();
            if(!vis[c]){
                vis[c] = 1;
                l.push(c);
            }
            else{
                while(l.front()!=c){
                    l.pop();
                }
            }
            for(int i=1; i<=l.size(); i++){
                if(l.front()==T) ans[T]++;
            }
        }
    }
    for(int i=1; i<=m; i++) cout << ans[i] << ' ';

    return 0;
}
