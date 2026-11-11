#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=200000+10;
const int maxm=200000+10;
int a[maxn],ans[maxm],t[maxm];
stack<int> st;
int n,m;
int main(){
    freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
 //   ans[a[n]]=n;
    for(int i=1;i<=n;i++){
        memset(t,0,sizeof(t));
        for(int j=i;j<=n;j++){
            if(t[a[j]]>0){
                while(!st.empty()){
                    if(st.top()==a[j]) break;
                    st.pop();
                 //   cout<<"p";
                }
            }else{
                t[a[j]]++;
                st.push(a[j]);
            }

        }
        while(!st.empty()){
            int qwe=st.top();
            st.pop();
          //  cout<<" qwe"<<qwe;
            ans[qwe]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}// 10 3
// 3 1 2 1 3 2 3 1 2 1
