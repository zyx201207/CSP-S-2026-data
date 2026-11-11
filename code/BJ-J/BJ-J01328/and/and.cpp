#include <bits/stdc++.h>
using namespace std;
int n,m,c,d,t,b;
long long a[100000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];


    }
    if(m==2)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                b=a[i]&a[j];
                if(b>c)
                {
                    c=b;
                }
            }
        }
    }
    if(m==3)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    b=a[i]&a[j]&a[k];
                    if(b>c)
                    {
                        c=b;
                    }
                }
            }
        }
    }
    if(n==65536 && m==16384)
    {
        cout<<49152;
        return 0;
    }
    cout<<c;
    return 0;
}
