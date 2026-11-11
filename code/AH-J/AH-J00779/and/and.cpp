#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    long long maxx=0,m1,m2;
    for(int i=2;i<=m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(a[k]!=-1&&a[j]!=-1)
                {
                    if(maxx<(a[j]&a[k]))
                    {
                        maxx=(a[j]&a[k]);
                        m1=j;
                        m2=k;
                    }
                }

            }
        }
        a[m1]=-1;
        a[m2]=-1;
    }
    cout<<maxx;
    return 0;
}
