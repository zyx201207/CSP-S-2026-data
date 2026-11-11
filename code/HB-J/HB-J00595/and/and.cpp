#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int a[N],m,n,ans;
bool book[N];
void dfs(int cnt,int num,int flag)
{
    book[flag]=1;
    if(num>=m)
    {
        ans=max(ans,cnt);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(book[i]==1) continue;
        dfs(cnt&a[i],num+1,i);
        book[i]=0;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==m)
    {
        int ans=1;
        for(int i=1;i<=n;i++) ans=ans&a[i];
        cout<<ans;
    }
    else
    {
        dfs(INT_MAX,0,0);
    }
    cout<<ans;
    return 0;
}
