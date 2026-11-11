#include<bits/stdc++.h>
using namespace std;
int n,m,a[1100000],t[1100000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        stack<int>st;
        for(int j=i;j<n;j++){
            stack<int>tmpst;
            if(st.size()!=0){
                while(!st.empty()){
                    int tmp=st.top();
                    st.pop();
                    tmpst.push(tmp);
                }
                while(!tmpst.empty()){
                    int tmp=tmpst.top();
                    if(tmp==a[j]){
                        break;
                    }
                    tmpst.pop();
                    st.push(tmp);
                }
            }
            st.push(a[j]);
        }
        while(!st.empty()){
            int tmp=st.top();
            t[tmp]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
