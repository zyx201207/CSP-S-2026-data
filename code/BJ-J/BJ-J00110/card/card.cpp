#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int a[1001],s[1001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            int j=0;
            stack<int> st2=st;
            while(!st2.empty()){
                j++;
                if(st2.top()==a[i]){
                    while(j-- && !st.empty()){
                        st.pop();
                    }
                    break;
                }
                st2.pop();
            }
            st.push(a[i]);
        }
        while(!st.empty()){
            s[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<s[i]<<' ';
    return 0;
}