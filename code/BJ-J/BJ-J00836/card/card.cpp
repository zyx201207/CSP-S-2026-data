#include <bits/stdc++.h>
#define N int(5e5+10)
using namespace std;
typedef long long ll;
map<ll,ll> bucket;
ll n,m,a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        map<ll,bool> visited;
        stack<ll> st;
        for(int j=i;j<=n;++j){
            if(visited[a[j]]==false){
                st.push(a[j]);
                visited[a[j]]=1;
            }else{
                ll t=st.top();
                while(t!=a[j]){
                    st.pop();
                    visited[t]=0;
                    t=st.top();
                }
                st.pop();
                st.push(a[j]);
                visited[a[j]]=1;
            }
        }
        map<ll,bool> visit;
        while(!st.empty()){
            if(visit[st.top()]==false){
                bucket[st.top()]++;
                visit[st.top()]=true;
            }
            st.pop();
        }
    }
    for(int k=1;k<=m;++k) cout<<bucket[k]<<' ';
    return 0;
}
