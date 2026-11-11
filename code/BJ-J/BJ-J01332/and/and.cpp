#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans,sum=1;
int a[200010];
/*void add(int x,int y){
    int a;
    if(x>y){
        a=x-y;
    }
    else{
        if(x<y){
            a=y-x;
        }
        else{
            a=x;
        }
    }
    while(){

    }
}*/
void dfs(int u,int w){
    if(u==n){
        if(w==m){
            ans=max(sum,ans);
        }
        return ;
    }
    dfs(u+1,w);
    if(w<m){
        //add(sum,a[u]);
        sum&=a[u];
        dfs(u+1,w+1);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,(long long)a[i]);
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
