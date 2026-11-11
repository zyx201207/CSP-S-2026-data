#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>0;i--)
    {
        long long shao=1e16,sum=0;
        for(int j=0;j<=n-i;j++)
        {
            for(int k=j;k<i+j-1;k++)
            {
                sum+=(a[i+j]-a[j+k+1]);
            }
            if(sum<=m) shao=min(shao,sum);

        }
        if(shao<10000000000000000)
        {
            cout<<i;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
