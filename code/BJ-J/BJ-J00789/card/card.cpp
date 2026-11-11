#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<int> q;
int n,m,a[500010],vis[300010],ans[300010],p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]) while(q.top()!=a[j]) vis[q.top()]--,q.pop();
            else q.push(a[j]),vis[a[j]]++;
        }
        while(!q.empty()){
            ans[q.top()]++;
            vis[q.top()]--;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
