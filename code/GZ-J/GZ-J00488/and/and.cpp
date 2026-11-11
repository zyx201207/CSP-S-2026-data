//GZ-J00488 ·½Åæç÷
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[20005],b[20005],maxx=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i]=a[n+1-i];
    for(int i=1;i<=n+1-m;i++)
    {
        long long x=2^30-1;
        for(int j=i;j<=i+m-1;j++)
            x&=b[j];
        if(x>maxx)maxx=x;
    }
    cout<<maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
