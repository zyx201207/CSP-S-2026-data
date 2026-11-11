#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],maxn=-1e9,b;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]>maxn)
            {
                maxn=a[i];
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        int s=a[0]^a[1];
        for(int i=2;i<n;i++)
        {
            s^=a[i];
        }
        cout<<s;
    }
    sort(a,a+n,cmp);
    if(m==2)
    {
        cout<<a[0]^a[1];
    }
    return 0;
}
