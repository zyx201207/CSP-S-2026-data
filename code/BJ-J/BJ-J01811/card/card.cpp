#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N],ans[N];
int vis[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        stack <int> s;
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                vis[a[j]]=1;
                s.push(a[j]);
            }else{
                while(!s.empty()&&s.top()!=a[j]){
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
