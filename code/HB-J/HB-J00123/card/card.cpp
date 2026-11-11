#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],pos[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(pos,0,sizeof(pos));
        stack<int> st;
        for(int j=i;j<=n;j++){
            if(pos[a[j]]){
                while(!st.empty()&&st.top()!=a[j]) pos[st.top()]=0,st.pop();
                st.pop();
                st.push(a[j]);
            }else pos[a[j]]=1,st.push(a[j]);
        }
        for(int i=1;i<=m;i++){
            if(pos[i]) ans[i]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
