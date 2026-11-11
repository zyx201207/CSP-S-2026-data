#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int cnt[300010];
int flag[300010];
stack<int> st;
void take(int a){
    for(int i=st.size();i>=a;i--){
        flag[st.top()]=0;
        st.pop();
    }
    return;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(flag,0,sizeof flag);
        st.push(a[i]);
        flag[a[i]]=1;
        for(int j=i+1;j<=n;j++){
            if(flag[a[j]]!=0){
                take(flag[a[j]]);
            }
            st.push(a[j]);
            flag[a[j]]=st.size();
        }
        while(!st.empty()){
            cnt[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
