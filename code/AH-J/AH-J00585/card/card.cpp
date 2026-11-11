#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],b[500005];
stack<ll> st;
bool vis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int t=1;t<=n;t++){
        for(int i=1;i<=m;i++)vis[i]=0;
        for(int i=t;i<=n;i++){
            if(!vis[a[i]]){
                st.push(a[i]);
                vis[a[i]]=1;
            }else{
                while(st.top()!=a[i]){
                    vis[st.top()]=0;
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            b[st.top()]++;st.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

