#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5+5;
int n, m;
int a[N];
int ans[N];
int cnt[N];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool flag = 1;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++) if(a[i]>a[i+1]) flag = 0;
    if(flag){
        int lastnum[N] = {};
        for(int i=1;i<=n;i++){
            lastnum[a[i]] = i;
        }
        for(int i=1;i<=m;i++){
            cout<<lastnum[i]<<' ';
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        stack<int> st;
        for(int j=i;j<=n;j++){
            if(!cnt[a[j]]){
                st.push(a[j]);
                cnt[a[j]]++;
            }
            else{
                while(st.top() != a[j]&&!st.empty()){
                    cnt[st.top()]--;
                    st.pop();
                }
            }
        }
        //if(cnt[3]>0) cout<<i<<'\n';
        for(int j=1;j<=m;j++) ans[j] += (cnt[j]>=1), cnt[j] = 0;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
