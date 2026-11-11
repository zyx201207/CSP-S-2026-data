#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int tong[1000000];
bool b[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
        stack<int> st;
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++){
            if(!b[a[j]]){
                st.push(a[j]);
                b[a[j]]=1;
            }
            else{
                while(st.top()!=a[j]){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            tong[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<tong[i]<<' ';
    }
    return 0;
}
//segmentation fault
