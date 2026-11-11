#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        stack<int> s;
        vector<bool> vis(m+10,0);
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(s.top()!=a[j]){
                    vis[s.top()]=0;
                    s.pop();
                }
            }
            else{
                s.push(a[j]);
                vis[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            //cout<<vis[i]<<' ';
            if(vis[j]) ans[j]++;
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}