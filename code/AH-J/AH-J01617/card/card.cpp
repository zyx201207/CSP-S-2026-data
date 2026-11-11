#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500010],cnt[300010];
bool vis[500010];
stack<LL> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(LL o=1;o<=n;o++){
        memset(vis,0,sizeof vis);
        for(LL i=o;i<=n;i++){
            if(vis[a[i]]){
                while(!st.empty()&&st.top()!=a[i]){
                    vis[st.top()]=false;
                    st.pop();
                }
                vis[st.top()]=false;
                st.pop();
            }
            st.push(a[i]);
            vis[a[i]]=true;
        }
        while(!st.empty()){
            cnt[st.top()]++;
            st.pop();
        }
    }
    for(LL i=1;i<=m;i++){
        printf("%lld ",cnt[i]);
    }
    return 0;
}
