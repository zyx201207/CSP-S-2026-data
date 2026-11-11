#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001];
long long c=0;
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
    for(int i=2;i<=n;i++)
    {
        int p=1,q=0;
        int x[i]={0};
        for(int j=1;j<i;j++)
        {
            x[j]=a[i]-a[j];
        }
        sort(x+1,x+i);
        for(int j=1;j<=i;j++)
        {
            if(q+x[j]<=m)
            {
                q+=x[j];
                p++;
            }
        }
        if(p>c)
        {
            c=p;
        }
    }
    cout<<c;
    return 0;
}
