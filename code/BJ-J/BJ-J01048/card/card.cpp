#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
stack<int> tr,trs;
set<int> st,sts;
int a[N],ans[M];
bool v[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=n;i>=1;i--){
        if(st.count(a[i])==0){
            st.insert(a[i]);
            tr.push(a[i]);
        }
        else{
            while(tr.top()!=a[i]){
                st.erase(tr.top());
                tr.pop();
            }
        }
        for(auto x=st.begin();x!=st.end();x++){
            ans[*x]++;
        }
    }
    for(int i=1;i<=m;i++)   cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}