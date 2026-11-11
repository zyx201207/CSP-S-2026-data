#include<bits/stdc++.h>
using namespace std;
int n,m,a[20000000],mx=-9999,v[20000000];
void dfs(int e,int j)
{
    if(e==m+1)
    {
        mx=max(mx,j);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            v[i]=1;
            if(j==-1)
            {
                dfs(e+1,a[i]);
            }
            else
            {
                dfs(e+1,j&a[i]);
            }
            v[i]=0;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,-1);
    cout<<mx;
    return 0;
}
