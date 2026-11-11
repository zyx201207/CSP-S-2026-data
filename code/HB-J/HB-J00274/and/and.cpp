#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], m, ans;
bool vis[N], st[N];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    //vis[i] = 1 means the numbers has lose
    for(int h = 30; h >= 0; h--){
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            if(!vis[i] && (a[i] >> h & 1)){
                cnt++;
            }else{
                st[i] = 1;
            }
        }
        if(cnt >= m){
            ans ^= (1<<h);
            for(int i = 1; i <= n; i ++){
                vis[i] |= st[i];
            }
        }
        for(int i = 1; i <= n; i ++){
            st[i] = 0;
        }
    }
    cout << ans;
    return 0;
}