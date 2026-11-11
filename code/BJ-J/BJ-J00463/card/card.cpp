#include <bits/stdc++.h>
using namespace std;
stack<int> stk,t;
int a[500005],vis[300005],ans[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(n>10000){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=n;i>=1;i--){
            //cout<<a[i]<<" "<<vis[a[i]]<<endl;
            if(!vis[a[i]]){
                stk.push(a[i]);
                vis[a[i]]=1;
            }
            else{
                while(!stk.empty() && stk.top()!=a[i]){
                    vis[stk.top()]=0;
                    stk.pop();
                }
            }
            while(!stk.empty()){
                t.push(stk.top());
                ans[stk.top()]++;
                //cout<<stk.top()<<"***\n";
                stk.pop();
            }
            while(!t.empty()){
                stk.push(t.top());
                t.pop();
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            //cout<<a[j]<<" "<<vis[a[j]]<<endl;
            if(!vis[a[j]]){
                stk.push(a[j]);
                vis[a[j]]=1;
            }
            else{
                while(!stk.empty() && stk.top()!=a[j]){
                    vis[stk.top()]=0;
                    stk.pop();
                }
            }
        }
        while(!stk.empty()){
            ans[stk.top()]++;
            //cout<<stk.top()<<"***\n";
            stk.pop();
        }
        memset(vis,0,sizeof(vis));
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
