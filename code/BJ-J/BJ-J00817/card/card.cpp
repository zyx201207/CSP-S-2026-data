#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int n,m,a[100010],d[100010];
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1,ans=0;i<=m;i++,ans=0){
        for(int j=1;j<=n;j++){
            memset(d,0,sizeof(d));
            stack<int> st;
            for(int k=j;k<=n;k++){
                if(d[a[k]]==0) st.push(a[k]),d[a[k]]=1;
                else while(st.top()!=a[k]) d[st.top()]=0,st.pop();
            }ans+=(d[i]?1:0);
        }cout<<ans<<" ";
    }cout<<endl;
    return 0;
}