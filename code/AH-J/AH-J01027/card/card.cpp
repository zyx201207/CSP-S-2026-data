#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,k=1;
int a[N],f[M];
bool t[M];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) k=0;
    }
    if(k){
        for(int i=n;i>=1;i--){
            if(a[i]!=a[i+1]) f[a[i]]+=i;
        }
    }else{
        for(int j=1;j<=n;j++){
            memset(t,0,sizeof(t));
            stack<int> st;
            for(int i=j;i<=n;i++){
                if(t[a[i]]==0){
                    st.push(a[i]);
                    t[a[i]]=1;
                }else{
                    while(!st.empty()){
                        if(st.top()!=a[i]){
                            t[st.top()]=0;
                            st.pop();
                        }else{
                            break;
                        }
                    }
                }
            }
            for(int i=1;i<=m;i++){
                f[i]+=t[i];
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<f[i]<<" ";
    return 0;
}
