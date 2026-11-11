#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long m,n,max_and=0;
    cin>>n>>m;
    long long a[100000000000000000000000];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int m1=m;
        long long cs_and=a[i]&&a[i+1];
        for(int j=i+2;j<=m;j++)
        {
            cs_and=cs_and&&a[j];
        }
        max_and=max(max_and,cs_and);
    }
    cout<<max_and;
    return 0;
}
