#include <bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
long long sum,num=1,m,n,maxx=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-1;i++)
    {
        b[i]=a[i+1]-a[i];
    }
    if(n<=1000)
    {
        for(int i=1;i<=n-1;i++)
        {
            num=1;
            sum=0;
            for(int j=i;j<=n-1;j++)
            {
                sum+=j*b[j];
                if(sum>m)
                {
                    maxx=max(maxx,num);
                    break;
                }
                else
                {
                    num++;
                }
            }
        }
        cout<<maxx;
    }
    else
    {
        for(int i=1;i<=n-1;i++)
        {
            sum+=i*b[i];
            if(sum>m)
            {
                cout<<num;
                break;
            }
            else
            {
                num++;
            }
        }
    }

    return 0;
}

