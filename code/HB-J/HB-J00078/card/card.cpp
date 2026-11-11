#include<bits/stdc++.h>
using namespace std;
bool instack[300010];
int cnt[300010];
int a[300010];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int sum = 0;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int k = 1;k <= n;k++){
        while(!st.empty()) st.pop();
        memset(instack,0,sizeof(instack));
        for(int i = k;i <= n;i++){
            int x = a[i];
            if(instack[x]){
                while(st.top() != x){
                    instack[st.top()] = 0;
                    st.pop();
                }
            }
            else{
                st.push(x);
                instack[x] = 1;
            }
        }
        for(int j = 1;j <= m;j++){
            if(instack[j]) cnt[j]++;
        }
    }
    for(int i = 1;i <= m;i++) cout<<cnt[i]<<" ";
    return 0;
}
