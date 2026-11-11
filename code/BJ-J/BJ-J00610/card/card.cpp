#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
stack <int> st;
int a[300005];
set<int> s;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(s.count(a[j])==0){
                s.insert(a[j]);
                st.push(a[j]);
            }
            else{
                while(1){
                    if(st.top()==a[j]){
                        s.erase(a[j]);
                        break;
                    }
                    int w=st.top();
                    st.pop();
                    s.erase(w);
                }
            }
        }
        s.clear();
        while(!st.empty()){
            mp[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<mp[i]<<" ";
    }
    return 0;
}
