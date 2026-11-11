#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],t[300010],cnt[300010];
stack<int> st;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(cnt[a[j]]==0){
                cnt[a[j]]++;
                st.push(a[j]);
            }else{
                cnt[a[j]]=1;
                while(st.top()!=a[j]){
                    cnt[st.top()]=0;
                    st.pop();
                }
            }
        }
        for(int i=1;i<=m;i++) if(cnt[i]!=0) cnt[i]=0,t[i]++;
    }
    for(int i=1;i<=m;i++) cout<<t[i]<<" ";
    return 0;
}
