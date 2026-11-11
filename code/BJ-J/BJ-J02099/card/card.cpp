#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int a[500010],ans[300010];
bool vis[300010];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        for (int j=i;j<=n;j++){
            if (!vis[a[j]]){
                st.push(a[j]);
                vis[a[j]]=true;
            }else{
                while (st.top()!=a[j]){
                    vis[st.top()]=false;
                    st.pop();
                }
            }
        }
        while (st.size()){
            ans[st.top()]++;
            st.pop();
        }
    }
    for (int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
