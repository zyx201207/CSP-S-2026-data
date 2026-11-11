#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[100005],c=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(i==j)
            {
                for(int k=j;k<=n;k++)
                {
                    b[i]=a[k];
                    c=k;
                }
            }
        }
    }
    for(int i=c;i>=1;i--)
    {
        cout<<b[i];
    }
    cout<<m;
    return 0;
}

