#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[5000],vis[3000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >>n>>m;
        for(int i=1;i<=n;i++){
                int sum[100000];
                stack<int> st;
            for(int j=i;j<=n;j++){
                    if(sum[arr[j]]==0){
                        sum[arr[j]]=1;
                        st.push(arr[j]);
                    }

                else{

                    while(true){
                        if(st.top()==arr[j]){
                            break;
                        }
                        sum[st.top()]=0;
                        st.pop();
                    }

                }
            }
            int k=st.size();
            int u[k+5];
            for(int j=1;j<=k;j++){
                u[j]=st.top();
                st.pop();
                vis[u[j]]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<vis[i]<<" ";
        }
    return 0;
}
