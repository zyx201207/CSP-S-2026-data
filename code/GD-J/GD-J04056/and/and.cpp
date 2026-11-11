#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=0,max=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=0;i<n-1;i++)
    {
        b[i]=(a[i]&a[i+1]);
    }
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<n-2;j++)
        {
            ans=(b[i]&a[i+2]);
            if(ans>max)
            {
                max=ans;
            }
        }
    }
    cout<<max;
    return 0;
}
