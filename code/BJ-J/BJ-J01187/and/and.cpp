#include <bits/stdc++.h>
using namespace std;
int a[210000];
int v[210000];
    int n,m;
    int max_1;
void dfs(int s,int l)
{
    if(l==m)
    {
        max_1=max(s,max_1);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            v[i]=1;
            if(l==0)
                dfs(a[i],l+1);
            else
                dfs(s&a[i],l+1);
            v[i]=0;
        }

    }

}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dfs(0,0);
    cout<<max_1;
    return 0;
}
