#include <bits/stdc++.h>
using namespace std;
int a[200010],a1[200],a2[200];
int pp(int a,int b)
{
    int sum=1;
    int cnt=0;
    int tmp=0,tmp1=0;
    while(a>0)
    {
        a1[tmp++]=a%2;
        a/=2;
    }
    while(b>0)
    {
        a2[tmp1++]=b%2;
        b/=2;
    }
    for(int i=0;i<=min(tmp,tmp1)-1;i++)
    {
        cnt+=sum*(a1[i]&&a2[i]);
        sum*=2;

    }
    return cnt;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    sort(a+1,a+n+1);
    long long ans=0;
    long long l,r;
    long long cnt=1;
    for(int k=2;k<=m;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(i!=j)
                {
                    if(ans<pp(a[i],a[j]))
                    {
                        l=i;
                        r=j;
                        ans=pp(a[i],a[j]);
                    }
                }
            }
        }
        a[l]=a[r]=0;
    }

    //ans=n&&m;
    cout <<ans;
    return 0;
}
