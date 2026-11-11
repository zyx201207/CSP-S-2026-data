#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
int n,m,a[N],b[N],vis[N];
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> st;
        fill(b+1,b+m+1,0);
        for(int j=i;j<=n;j++){
            if(b[a[j]]==0){
                b[a[j]]=st.size()+1;
                st.push(a[j]);
            }else{
                //cout<<b[a[j]]<<'\n';
                int len=b[a[j]];
                for(int k=1;k<=st.size()-len+1&&!st.empty();k++){
                    //cout<<st.top()<<" ";
                    b[st.top()]=0;
                    st.pop();
                }
                b[a[j]]=st.size()+1;
                st.push(a[j]);
                //cout<<'\n';
            }
        }
        for(int j=1;j<=m;j++){
            if(b[j]){
                //cout<<j<<" ";
                vis[j]++;
            }
        }
        //cout<<'\n'<<"----------------------"<<'\n'<<i+1<<'\n';
    }
    for(int i=1;i<=m;i++){
        cout<<vis[i]<<" ";
    }
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
