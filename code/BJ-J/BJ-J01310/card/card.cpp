#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],f[300001],s[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++){
        stack<int>st;
        memset(f,0,sizeof(f));
        for(int j=i;j<=n;j++){
            if(!f[a[j]]){
                st.push(a[j]);
                f[a[j]]=1;
            }
            else{
                while(st.top()!=a[j]){
                    f[st.top()]--;
                    st.pop();
                }
            }
        }
        for(int j=1;j<=m;j++)s[j]+=f[j];
    }
    for(int i=1;i<=m;i++)cout<<s[i]<<' ';
    return 0;
}
