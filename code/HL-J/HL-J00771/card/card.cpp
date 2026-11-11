#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[300010];
ll a[500010],n,m,ans[300010];
int main()
{
    scanf("%lld%lld",&n,&m);
    for(register int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(register int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        stack<ll > st;
        for(int j=i+1;j<=n;j++){
            if(vis[a[j]]==0){
                vis[a[j]]=1;
                st.push(a[j]);
            }else{
                while(!st.empty()){
                    if(st.top()==a[j])break;
                    else{
                            st.pop();
                            vis[st.top()]=0;
                    }
                }
            }
        }
        while(!st.empty())
        {
            a[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)printf("%lld ",a[i]);
}
