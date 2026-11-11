#include<bits/stdc++.h>
using namespace std;
int s[500005];
int num[300005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        memset(num,0,sizeof(num));
        stack<int> st;
        for(int j=i;j<=n;j++){

            if(num[s[j]]==0){
                st.push(s[j]);
                num[s[j]]++;
            }
            else{
                while(st.top()!=s[j]){
                    num[st.top()]--;
                    st.pop();
                }
            }
        }
        for(int i=1;i<=m;i++){
            ans[i]+=num[i];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
