#include<bits/stdc++.h>
using namespace std;

int n,a[200010],m,mn;
void dfs(int n,int p,int w,int now,int maxn)
{
    if(w==n)
    {
        mn=max(mn,maxn);
        return ;
    }
    for(int i=w;i<n-p;i++)
    {
        if(p==m-1)now=a[i];
        else maxn=max(maxn,now&a[i]);
        if(p!=m-1)dfs(n,p-1,w+1,now&a[i],maxn);
        else dfs(n,p-1,w+1,now,maxn);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    dfs(n,m-1,0,0,0);
    cout<<mn<<endl;
}
