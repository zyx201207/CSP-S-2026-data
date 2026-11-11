#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500005]={},t[300005]={},s[300005]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int>st;
        for(int j=i;j<=n;j++){
            if(s[a[j]]==0){
                st.push(a[j]);
                //cout<<st.top();
                s[a[j]]++;
            }else{
                //int u=st.top();
                while(st.top()!=a[j]){
                    s[st.top()]--;
                    st.pop();
                    //u=st.top();
                }
            }
        }
        while(st.empty()!=1){
            int u=st.top();
            t[u]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
