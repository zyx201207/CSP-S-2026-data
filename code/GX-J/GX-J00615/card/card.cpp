#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],d;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]!=d)
            {
                d=a[j];
                ans[d]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
