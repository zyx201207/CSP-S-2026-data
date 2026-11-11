#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,m;
int a[maxn],ans[maxn];
bool vis[maxn];
stack<int> c;
void fin(){

    while(!c.empty()){
        ans[c.top()]++;
        vis[c.top()]=false;
        c.pop();
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        vis[i]=false;
    }
    for(int i=0;i<=m;i++){
        ans[i]=0;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            c.push(a[j]);
            if(vis[a[j]]==true){
                vis[a[j]]=false;
                c.pop();
                while(c.top()!=a[j]){
                    vis[c.top()]=false;
                    c.pop();
                }
            }
            else vis[a[j]]=true;
        }
        fin();
    }
    for(int i=1;i<=m;i++){
        if(ans[i]!=0){
            cout<<ans[i]<<" ";
        }

    }
    return 0;
}
