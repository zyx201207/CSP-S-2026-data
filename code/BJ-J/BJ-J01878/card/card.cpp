#include<bits/stdc++.h>
using namespace std;
int a[500006],ans[300006];
bool vis[300006];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int t=1;t<=n;t++){
        for (int i=t;i<=n;i++){
            if (vis[a[i]]){
                while (s.top()!=a[i]) {
                    vis[s.top()]=0;
                    s.pop();
                }
            }
            else {
                s.push(a[i]);
                vis[a[i]]=1;
            }
        }
        for (int i=1;i<=m;i++){
            ans[i]+=vis[i];
            vis[i]=0;
        }

    }
    for (int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
