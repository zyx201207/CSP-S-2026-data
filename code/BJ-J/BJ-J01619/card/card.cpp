#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[5005];
int cnt[3005];
int vis[3005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m ;
    for(int i = 1; i <= n; i++){
        cin >> a[i] ;
    }
    for(int i = 1; i <= n; i++){
        memset(vis,0,sizeof(vis));
        deque<int> dq;
        for(int j = i; j <= n; j++){
            if(vis[a[j]]){
                while(dq.size() && a[dq.back()] != a[j]){
                    vis[a[dq.back()]] = 0;
                    dq.pop_back();
                }
                vis[a[j]] = 0;
                dq.pop_back();
            }
            else{
                vis[a[j]] = 1;
                dq.push_front(j);
            }
            int t = dq.size();
            while(t--){
                int p = dq.front();
                dq.push_back(dq.front());
                cnt[p]++;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        cout << cnt[i] << " " ;
    }
    return 0;
}
