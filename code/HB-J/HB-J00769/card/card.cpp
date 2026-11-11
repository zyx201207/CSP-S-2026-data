#include<bits/stdc++.h>
#define int long long
using namespace std;
stack<int> s;
int vis[333333],a[555555],x[333333],n,m;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(s.size() && !s.empty()) s.pop();
        memset(vis,0,sizeof vis);
        for(int j=i;j<=n;j++){
            if(vis[a[j]] && s.size()){
                while(s.top()!=a[j] && s.size()) s.pop();
                if(s.size()) s.pop();
                vis[a[j]]=0;
            }
            s.push(a[j]);
            vis[a[j]]=1;
        }
        while(s.size()){
            vis[s.top()]=0;
            x[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}
