#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int n,m;
const int MAXN=2e5+10;
int a[MAXN];
int ans=0;

void dfs(int x,int sum)
{
    if(x==m+1)
    {
        ans=max(ans,sum);
    }

    for(int i=x;i<=n;i++)
    {
        dfs(x+1,sum&a[i]);
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    dfs(1,1);

    cout<<ans;

    return 0;
}
