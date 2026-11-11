#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        int ma=-1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=ma)
                ma=a[i];
        }
        cout<<ma;
        return 0;
    }
    else if(m==2)
    {
        int ma=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if((a[i]&a[j])>=ma)
                    ma=(a[i]&a[j]);
            }
        }
        cout<<ma;
        return 0;
    }
    else if(m==n)
    {
        int ma=a[1];
        for(int i=2;i<=n;i++)
        {
            ma=(ma&a[i]);
        }
        cout<<ma;
        return 0;
    }
    else
        cout<<0;
    return 0;
}
