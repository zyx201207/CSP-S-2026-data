#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[200005],ans;
bool vis[200005];
int dfs(int step,int start,int x)
{
    if(step>=m){
        ans=max(ans,x);
        return 0;
    }
    if(start==n)return 0;
    for(int i=start+1;i<=n;i++)
    {
        vis[i]=1;
        dfs(step+1,i,x&a[i]);
        vis[i]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==m){
        ans=a[1];
        for(int i=2;i<=n;i++)
            ans=ans&a[n];
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(1,i,a[i]);
        vis[i]=0;
    }
    cout<<ans;
    return 0;
}

