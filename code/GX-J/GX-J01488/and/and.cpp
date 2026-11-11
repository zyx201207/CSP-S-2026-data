#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,zd=0,tj,xb;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        tj=a[i];
        xb=i;
        for(int j=0;j<m;j++)
        {
            if(j!=xb)
            {
                tj=tj and a[j];
            }
        }
        if(tj>zd)
            zd=tj;
    }
    cout<<zd;

    return 0;
}
