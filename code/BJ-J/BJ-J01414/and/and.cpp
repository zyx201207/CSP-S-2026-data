#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxx=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=m;j++)
            {
                if(a[i]&a[j]>maxx)
                {

                    maxx=(a[i]&a[j]);
                }
            }
    }
    cout<<maxx;
    return 0;
}
