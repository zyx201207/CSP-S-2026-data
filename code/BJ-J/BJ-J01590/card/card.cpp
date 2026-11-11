#include<bits/stdc++.h>
using namespace std;
queue<long long> q;
stack<long long> s;
long long a[500000+5],vis[500000+5],ans[500000+5];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++) q.push(a[j]);
        memset(vis,false,sizeof(vis));
        for(long long j=i;j<=n;j++){
            s.push(q.front());
            if(vis[s.top()]){
                s.pop();
                while(s.top()!=q.front()){
                    vis[s.top()]=false;
                    s.pop();
                }
            }
            else vis[s.top()]=true;
            q.pop();
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
    return 0;
}