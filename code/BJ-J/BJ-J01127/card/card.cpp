#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> sum(m+5,0);
    vector<int> vec(n+5,0);
    for(int i=0;i<n;i++) cin>>vec[i];
    for(int i=0;i<n;i++){
        stack<int> st;
        vector<int> t(m+5,0);
        for(int j=i;j<n;j++){
            while(t[vec[j]-1]){
                int x=st.top();
                t[x-1]--;
                st.pop();
                if(x==vec[j]) break;
            }
            st.push(vec[j]);
            t[vec[j]-1]++;
        }
        while(!st.empty()){
            sum[st.top()-1]++;
            st.pop();
        }
    }
    for(int i=0;i<m;i++) cout<<sum[i]<<" ";
    return 0;
}
