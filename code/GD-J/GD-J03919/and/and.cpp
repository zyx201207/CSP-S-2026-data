#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int abs(int a,int b)
{
    int c[10005],f[10005];
    int d=1,g=1,sum,num=0;
    while(a>0)
    {
        if(a%2==1)
        {
            a=a/2;
            c[d] = 1;
            d++;

        }
        else
        {
            a=a/2;
            c[d] = 0;
            d++;
        }
    }

    while(b>0)
    {
        if(b%2==1)
        {
            b=b/2;
            f[g] = 1;
            g++;

        }
        else
        {
            b=b/2;
            f[g] = 0;
            g++;
        }
    }
    if(d>=g)
        sum = g;
    else
        sum = d;

    for(int i=1;i<=sum;i++)
    {
        if(c[i]==f[i])
        {
            num += c[i]<<i;
        }
    }
    return num/2;
}
int n,m,y[1005],dp[10005];
int main()
{
    freopen("string.in","r",stdin);
    freoprn("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>y[i];
    }
    if(m==1||m==2)
    {
        for(int i=1;i<=n;i++)
        {
            dp[i] = max(dp[i-1],abs(y[i],y[i-1]));
        }
        cout<<dp[n];
    }






}
