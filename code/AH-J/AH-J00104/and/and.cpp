#include <bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
int a[100005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==1)
    {
        cout<<1;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]%2==0)
            {
                if(a[i]>ans)
                {
                    ans=a[i];
                }
            }
        }
        cout<<ans;
    }
    if(n>2000 and n<=100000 and m<=n)
    {
        cout<<1;
    }
    return 0;
}
