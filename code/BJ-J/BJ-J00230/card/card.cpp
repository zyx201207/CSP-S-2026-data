#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005,M = 3005;
int n,m;
int a[N];
int buc[M];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int t = 1;t <= n;t++){
        bool vis[M] = {};
        stack<int> st = {};
        for(int i = t;i <= n;i++){
            if(vis[a[i]]){
                //cout<<a[i]<<endl;
                while((!st.empty())){
                    if((st.top() == a[i] ))
                    break;
                    vis[st.top()]=0;
                    st.pop();
                }
            }else
            st.push(a[i]);
            vis[a[i]] = 1;
        }
        while(!st.empty()){
            buc[st.top()] ++;
            st.pop();
        }
    }
    for(int i = 1;i <= m;i++)
        cout<<buc[i]<<" ";
return 0;
}
