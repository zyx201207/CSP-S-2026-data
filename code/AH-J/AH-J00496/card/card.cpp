#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500010],cnt[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    for(LL js=1;js<=n;js++){
        deque<LL>q,qq;
        for(LL i=js;i<=n;i++){
            q.push_back(a[i]);
        }
        while(!q.empty()){
            LL x=q.front();q.pop_front();
            bool ok=0;
            stack<LL>st;
            while(!qq.empty()){
                if(qq.front()==x){
                    ok=1;
                    while(!qq.empty()){
                        qq.pop_front();
                    }
                    qq.push_front(x);
                    break;
                }
                st.push(qq.front());
                qq.pop_front();
            }
            while(!st.empty()){
                qq.push_front(st.top());
                st.pop();
            }
            if(!ok)qq.push_back(x);
        }
        while(!qq.empty()){
            cnt[qq.front()]++;
            qq.pop_front();
        }
    }
    for(LL i=1;i<=m;i++){
        if(cnt[i]!=0){
            cout<<cnt[i]<<" ";
        }
    }
    return 0;
}
