#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[919191];
int ans[919191];
int b[919191];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[a[j]]==0){
                b[a[j]]=1;
                st.push(a[j]);
            }
            else{
                while(st.top()!=a[j]){
                    b[st.top()]=0;
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans[st.top()]++;
            b[st.top()]=0;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
