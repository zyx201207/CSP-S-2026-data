#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int n,m,a[500005],t[300005];
stack<int> q;
bool vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000){
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            for(int j=i;j<=n;j++){
                if(!vis[a[j]]){
                    q.push(a[j]);
                    vis[a[j]]=1;
                }else{
                    while(q.top()!=a[j]){
                        vis[q.top()]=0;
                        q.pop();
                    }
                }
            }
            while(!q.empty()){
                t[q.top()]++;
                q.pop();
            }
        }
        for(int i=1;i<=m;i++){
            cout<<t[i]<<" ";
        }
    }else{
        for(int i=1;i<=n;i++){
            t[a[i]]=i;
        }
        for(int i=1;i<=n;i++){
            cout<<t[i]<<" ";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
