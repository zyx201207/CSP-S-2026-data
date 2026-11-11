#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300003],x;
//maxn=5e5, maxm=3e5
bool vis[300003];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        stack<int> st;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(st.top()!=a[j]){
                    vis[st.top()]=false;
                    st.pop();
                }
            }else{
                st.push(a[j]);
                vis[a[j]]=true;
            }
        }
        while(!st.empty()){
            x=st.top();st.pop();
            ans[x]++;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
    printf("\n");
}