#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int> a(n+5);
    vector<int> r(m+5);
    vector<int> ans(m+5);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        for(int i = 1;i<=m+5;i++){
            r[i] = 0;
        }
        stack<int> st;
        for(int j = i;j<=n;j++){
            st.push(a[j]);
            r[a[j]] ++;
            if(r[a[j]] > 1){
                while(!r[j] && !st.empty()){
                    r[st.top()] --;
                    st.pop();
                }
                st.push(a[j]);
                r[a[j]] ++;
            }
        }
        for(int j = 1;j<=m;j++){
            ans[j] += r[j];
        }
    }
    for(int i = 1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
