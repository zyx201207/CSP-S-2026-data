#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int k=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==i)
            {
                continue;
            }
            else
            {
                int x=a[i]&&a[j];
                k=max(k,x);
            }
        }
    }
    cout<<k;
    return 0;
}
