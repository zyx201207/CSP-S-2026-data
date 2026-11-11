#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        stack<int> st;
        int pos=0;
        string s;
        for(int j=i;j<=n;j++){
            s[pos]=a[j];
            bool flag=0;
            int flagpos=0;
            for(int k=pos-1;k>=0;k--){
                if(s[k]==a[j]){
                    flag=1;
                    flagpos=k;
                    break;
                }
            }
            if(flag){
                while(st.top()!=a[j]) st.pop();
                for(int k=pos-1;k>flagpos;k--) s[k]=0;
                pos=flagpos+1;
            }
            else{
                st.push(a[j]);
                pos++;
            }
        }
        while(!st.empty()){
            ans[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}