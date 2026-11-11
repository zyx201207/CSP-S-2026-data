#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int>a(n+1), ans(m+1, 0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int>cnt(m+1, 0);
        stack<int>s;
        for(int j=i; j<=n; j++){
            cnt[a[j]]++;
            if(cnt[a[j]]>=2){
                while(!s.empty()&&cnt[a[j]]>=2){
                    cnt[s.top()]--;
                    s.pop();
                }
            }
            s.push(a[j]);
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1; i<=m; i++){
        cout << ans[i] << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
