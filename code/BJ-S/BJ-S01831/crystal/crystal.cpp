#include<bits/stdc++.h>
using namespace std;
const int NN = 1e8+1000;
long long n,m;
long long cnt=1;
long long mm;
long long a[500010];
long long b[500010];
long long c[NN];
long long dp[10000][10000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long maxn=-100;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    c[1]=1;
    c[2]=3;
    c[3]=6;
    c[4]=10;

    bool flag=0;
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++)
    {
        if(a[i]==a[i+1]) cnt++;
        if(a[i]!=i) flag=1;
        b[i]=a[i]-a[i-1];

    }
    if(m==0){
        cout<<cnt;
        return 0;
    }
    for(long long i=5;i<=100000000;i++)
    {
        c[i]=i*i-c[i-1];
    }
    for(long long i=5;i<=100000000;i++)
    {

        if(m>c[i]&&m<c[i+1])
        {

            mm=i+1;
        }
        if(m==c[i])
        {
            mm=i+1;
        }
    }
    if(flag==0)
    {
        cout<<mm;
        return 0;
    }
    for(long long i=1;i<=n-1;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
            dp[i][j]=dp[i][j-1]+b[j];
        }
    }
    for(long long i=1;i<=n-1;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
            if(dp[i][j]<=m)
            {
                if((j-i)>maxn) maxn=j-i;

            }
        }
    }
    cout<<maxn+1;




    return 0;
}
