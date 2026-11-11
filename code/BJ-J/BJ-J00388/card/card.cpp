#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
int vis[300005];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int k=1;k<=n;k++){
        for(int i=1;i<=m;i++)vis[i]=0;
        while(st.size())st.pop();
        for(int i=k;i<=n;i++){
            if(vis[a[i]]){
                while(1){
                    if(st.top()==a[i]){
                        st.pop();
                        st.push(a[i]);
                        break;
                    }else{
                        int x=st.top();
                        vis[x]=0;
                        st.pop();
                    }
                }
            }else{
                vis[a[i]]=1;
                st.push(a[i]);
            }
        }
        for(int i=1;i<=m;i++){
            if(vis[i])
                ans[i]++;
        }
    }
    for(int i=1;i<=m;i++){
            if(ans[i])
                cout<<ans[i]<<' ';
        }
    return 0;
}
