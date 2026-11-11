#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> v(n+1);
    vector<long long> cnt(m+1,0);
    for (int i=1;i<=n;i++) cin>>v[i];
    for (int i=1;i<=n;i++){
        stack<int> q;
        vector<bool> vis(m+1,false);
        for (int j=i;j<=n;j++){
            if (vis[v[j]]){
                while (!q.empty() && q.top()!=v[j]){
                    vis[q.top()]=false;
                    q.pop();
                }
                vis[q.top()]=false;
                q.pop();
            }
            q.push(v[j]);
            vis[v[j]]=true;
        }
        while (!q.empty()){
            cnt[q.top()]++;
            q.pop();
        }
    }
    for (int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}