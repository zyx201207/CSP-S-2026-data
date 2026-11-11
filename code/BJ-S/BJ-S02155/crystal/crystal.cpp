#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[1000005];
long long b[1000005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    a[0]=-1e14;
    for (int k=1;k<=n;k++)
    {

        long long i=k-1,m1=m,as=1;
        for (int i=k-1;i>=1;i--)
        {
            int i1=a[k]-a[i];
            if (m1>=i1)
            {
                m1-=i1;
                as++;
            }
            else
            {
                break;
            }
        }
        ans=max(ans,as);
    }
    cout<<ans;



    fclose(stdin);
    fclose(stdout);
    return 0;
}
