#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002],ans;
void dfs(int xu,int nowa,int nowai){
    if(xu==m){
        ans=max(ans,nowa);
        return;
    }
    if(nowai>n&&xu!=m){return;}
    int newa=nowa&a[nowai];
    if(newa==0)newa=a[nowai];
    dfs(xu+1,newa,nowai+1);
    dfs(xu,nowa,nowai+1);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(0,0,1);
    cout<<ans;

    return 0;
}