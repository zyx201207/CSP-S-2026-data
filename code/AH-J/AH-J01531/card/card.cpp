#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
stack<int> st;
map<int,int> t,t2;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        t.clear();
        for(int j=i;j<=n;j++){
            if(st.empty()){
                st.push(a[j]);
                t[a[j]]++;
            }else{
                if(t[a[j]]>0){
                    while(st.top()!=a[j]){
                        int x=st.top();
                        t[x]--;
                        st.pop();
                    }
                }else{
                    st.push(a[j]);
                    t[a[j]]++;
                }
            }
        }
        while(!st.empty()){
            int x=st.top();
            t2[x]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t2[i]<<" ";
    }
    return 0;
}
