#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000005];
int maxx=INT_MIN;
void dfs(int value,int step,int id){
    if(value>maxx&&step==m){
        maxx=value;
    }
    if(step>m)return;
    for(int i=1;i<=n;i++){
        if(id==i) continue;
        dfs(value&a[i],step+1,i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(a[i],1,i);
    }
    cout<<maxx;
    return 0;
}
