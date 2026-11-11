#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],pos[300005];
bool vis[300005],f=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
        if(a[i]<a[i-1]){
            f=0;
        }
    }
    if(m==1){
        cout<<n<<"\n";
        return 0;
    }
    if(f){
        for(int i=1;i<=m;i++){
            cout<<pos[i]<<' ';
        }
        cout<<"\n";
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        stack<int> stk;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(stk.top()!=a[j]){
                    vis[stk.top()]=0;
                    stk.pop();
                }
                continue;
            }
            stk.push(a[j]);
            vis[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            ans[j]+=vis[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    cout<<"\n";
    return 0;
}
