#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],in[M],vis[M];
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<int> st;
    for(int i=n;i>=1;i--){
        if(in[a[i]]==0){
            in[a[i]]=1;
            st.push(a[i]);
        }
        else{
            while(st.top()!=a[i]) st.pop();
        }
        for(int j=1;j<=m;j++) vis[i]+=in[i];
    }
    for(int i=1;i<=m;i++) cout<<vis[i]<<' ';
    return 0;
}
