#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;

int n,m;
int a[N],vis[N],ans[N];
bool ta=1;

void sa(){
    for(int i=1;i<=m;i++) cout<<n<<' ';
    exit(0);
}

void bl(){
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        stack<int> st;
        for(int j=i;j<=n;j++){
            int k=vis[a[j]];
            while(!st.empty()&&vis[a[j]]!=k) vis[st.top()]--,st.pop();
            st.push(a[j]);
            vis[a[j]]++;
        }
        while(!st.empty()) ans[st.top()]++,st.pop();
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    exit(0);
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) ta=0;
    }
    if(ta) sa();
    else bl();
}
/*
10 3
2 3 1 2 1 3 2 3 1 2 1
*/