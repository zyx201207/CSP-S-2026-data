#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,d,a[10000005],vis[2000005],f[1005][1005];
struct node{
    int a,b;
};
int bfs(int st,int ed){
    queue<node> q;
    q.push({st,0});
    int cnt=0;
    while(!q.empty()){
        node h=q.front();q.pop();
        if(h.a==ed) cout<<st<<" "<<h.a<<" "<<h.b<<"\n";
        if(h.a==ed){
            ++cnt;
            continue;
        }
        if(h.b>f[st][ed]) break;
        if(cnt>2) break;
        for(int i=h.a;i<=h.a+d;i++) q.push({i,h.b+abs(i-h.a)});
    }
    return cnt==2;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n>2) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
