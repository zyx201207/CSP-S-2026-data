#include<bits/stdc++.h>
#define ll long long
#define MAX 100010
using namespace std;
int a[MAX];
bool b[MAX];
int ans[MAX];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>5000){
        for(int i=n;i>=1;i--){
            b[a[i]]=1;
            for(int j=1;j<=m;j++){
                ans[j]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int j=1;j<=n;j++){
        stack<int> st;
        memset(b,0,sizeof b);
        for(int i=j;i<=n;i++){
            if(b[a[i]]==0){
                st.push(a[i]);
                b[a[i]]=1;
            }else{
                while(st.top()!=a[i]){
                    b[st.top()]=0;
                    st.pop();
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(b[i]==1){
                ans[i]++;
            }
        }
    }

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
