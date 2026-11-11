#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int cnt[300005];
bool vis[300005];
void c(int a[],int i){
    memset(vis,false,sizeof (vis));
    stack<int>st;
    for(int j=i;j<=n;j++){
        if(vis[a[j]]){
            while(st.top()!=a[j]){
                vis[st.top()]=false;
                st.pop();
            }
        }
        else{
            st.push(a[j]);
            vis[a[j]]=true;
        }
        cout<<endl;
    }
    while(!st.empty()){
        cnt[st.top()]++;
        st.pop();
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        c(a,i);
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
}