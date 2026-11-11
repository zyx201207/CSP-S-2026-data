#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],h[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> st;
        memset(h,0,sizeof(h));
        for(int j=i;j<=n;j++){
            if(h[a[j]]){
                while(!st.empty()){
                    if(st.top()!=a[j]){
                        h[st.top()]--;
                        st.pop();
                    }else{
                        break;
                    }
                }
            }else{
                h[a[j]]++;
                st.push(a[j]);
            }
        }
        while(!st.empty()){
            ans[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
