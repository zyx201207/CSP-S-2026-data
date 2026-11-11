#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
stack<int>st;
int n,m,a[N],cnt[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            st.push(a[j]);
            cnt[a[j]]++;
            if(cnt[a[j]]>=1){
                for(;cnt[a[j]]!=0;){
                    cnt[st.top()]--;
                    st.pop();
                }
                st.push(a[j]);
                cnt[a[j]]++;
            }
        }
        for(;!st.empty();){
            ans[st.top()]++;
            cnt[st.top()]=0;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
