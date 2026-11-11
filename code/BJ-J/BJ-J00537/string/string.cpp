#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200001],sum=0;
char c[200001];
char get(long long i)
{
    return c[lower_bound(a+1,a+n+1,i)-a];
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        long long me=min(a[i],a[n]/2),st=lower_bound(a+1,a+n+1,a[n]-me+1)-a,en=lower_bound(a+1,a+n+1,a[n]-a[i-1])-a;
        for(int j=st;j<=en;j++)
        {
            long long s=max(a[n]-me,a[j-1])+1,e=min(a[n]-a[i-1],a[j]);
            if(c[j]!=c[i])
                sum+=e-s+1;
        }
        if(a[i]>=a[n]/2)
            break;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
