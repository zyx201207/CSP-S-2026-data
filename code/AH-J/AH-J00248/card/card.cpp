#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],n,m,t[M];
bool vis[N];
stack<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==1){
                while(q.top()!=a[j]){
                    vis[q.top()]=0;
                    q.pop();
                }
                continue;
            }
            vis[a[j]]=1;
            q.push(a[j]);
        }
        while(!q.empty()){
            vis[q.top()]=0;
            t[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
