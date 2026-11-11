#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main ()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

    }
    long long x=a[n];
    int num=1;
    long long y;
    for(int i=n-1;i>=1;i--)
    {
        y=x-a[i];
        if(m>=y)
        {
            m=m-y;
            num++;
        }
        else
        {
            break;
        }
    }
    if(num>1)
    {
        printf("%d",num);
    }
    else
    {
        printf("%d",0);
    }


    return 0;
}
