#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=3e5+5;
int n,m;
int cards[MAXN];int ans[MAXM];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cards[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> st;
        vector<bool> vis(m+1,0);
        for(int j=i;j<=n;j++){
            int cur=cards[j];
            if(!vis[cur]){
                vis[cur]=true;
                st.push(cur);
            }
            else{
                while(!st.empty()){
                    int t=st.top();
                    if(t==cur) break;
                    vis[t]=false;
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            int t=st.top();st.pop();
            ans[t]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
