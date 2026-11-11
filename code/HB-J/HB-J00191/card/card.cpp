#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans[200005];
int n,m;
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                bool ok=0;
            int x=1,y;
            int p[200005];
        while(!q.empty()){

                if(q.front()==a[j]){
                        q.pop();
                ok=1;
                int y=x-1;
            }
            p[x]=q.front();
            q.pop();
            x++;
        }
        if(!ok){
            for(int k=1;k<x;k++)q.push(p[k]);
        }
        else{
            for(int k=1;k<=y;k++)q.push(p[k]);
        }
        q.push(a[j]);
        }
        while(!q.empty()){
            for(int k=1;k<=m;k++){
                if(q.front()==k)ans[k]++;
            }
            q.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
