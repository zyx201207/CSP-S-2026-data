#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
bool b[300005];
int cnt[300005];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        b[i]=0;
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cnt[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                while(st.top()!=a[j]&&st.size()) st.pop();
            }
            else{
                st.push(a[j]);
                b[a[j]]=1;
            }
        }
        while(st.size()){
            cnt[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
