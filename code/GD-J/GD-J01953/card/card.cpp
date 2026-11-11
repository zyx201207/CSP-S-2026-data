#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    bool ok=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ok&=(a[i-1]<=a[i]);
    }
    if(ok){
        set<int> st;
        vector<int> ans(m+1);
        for(int i=n;i>=1;i--){
            st.insert(a[i]);
            for(int x:st) ans[x]++;
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" \n"[i==m];
    }
    else{
        vector<int> ans(m+1);
        deque<int> q;
        auto check=[&](int j)->bool{
            for(int x:q){
                if(x==j){
                    return true;
                }
            }
            return false;
        };
        for(int i=1;i<=n;i++){
            q.clear();
            for(int j=i;j<=n;j++){
                if(check(a[j])){
                    while(q.back()!=a[j]&&!q.empty()) q.pop_back();
                }
                else q.push_back(a[j]);
            }
            while(!q.empty()){
                ans[q.front()]++;
                q.pop_front();
            }
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" \n"[i==m];
    }
    return 0;
}