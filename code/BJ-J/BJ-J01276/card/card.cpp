# include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int vis[N];
int ans[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){//number i round
        stack<int>s;memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
              if(!vis[a[j]]){
                s.push(a[j]);
                vis[a[j]]=1;
              }  else{
                while(s.top()!=a[j]){
                    vis[s.top()]=0;
                    s.pop();
                }
              }
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
