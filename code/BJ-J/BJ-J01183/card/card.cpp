#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],f[M];
bool flag[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        stack<int> st;
        for(int j=i;j<=n;j++){
            if(flag[a[j]]){
                while(!st.empty()){
                    int cnt=st.top();
                    st.pop();
                    flag[cnt]=0;
                    if(cnt==a[j])
                        break;
                }
            }
            flag[a[j]]=1;
            st.push(a[j]);
        }
        while(!st.empty()){
            int cnt=st.top();
            st.pop();
            f[cnt]++;
            flag[cnt]=0;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<f[i]<<" ";
    return 0;
}