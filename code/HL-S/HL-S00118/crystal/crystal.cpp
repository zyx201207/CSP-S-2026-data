#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],dp[N],f[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,k=0,sum=0,ssi=0;
    cin>>n>>m;

    for(int i =1;i <=n;i++)
    {
        cin>>a[i];
        f[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            sum+=f[j]*ssi;
            ssi++;
            if(sum>m)
            {
                j-=1;
                dp[k++]=ssi-1;
                sum=0;
                ssi=0;
            }
        }
    }
    sum=0;
    for(int i=1;i<=k;i++)
        sum=max(sum,dp[i]);
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
