#include <bits/stdc++.h>

using namespace std;
int a[1000000000],dp[1000000000];
int n,m,sum=0,cnt=0;
int main()
{
    freopen("and","r",stdin);
    freopen("and","w",stdout);
    cin>>n>>m;
    for(int i=1 ; i<=n ; i++)
    {
        cin>>a[i];
    }
    sum=a[1];
    if(m==n)
    {
        for(int i=2 ; i<=n ; i++)
        {
            sum=sum&a[i];
        }
        cout<<sum;
        return 0;
    }
    if(m==2)
    {
        sum=-1000;
        for(int i=1 ; i<=n ; i++)
        {
            cnt=a[i];
            for(int j=i+1 ; j<=n ; j++)
            {
                int t=cnt&a[j];
                sum=max(t,sum);
            }
        }
        cout<<sum;
    }
    if(m==1)
    {
        for(int i=1 ; i<=n ; i++){
            sum=max(sum,a[i]);
        }
        cout<<sum;
    }
    if(m==n-1)
    {
        for(int i=1 ; i<=n ; i++)
        {
            cnt=a[i];
            for(int j=1 ; j<=n ; j++)
            {
                if(j==i)
                    continue;
                else{
                    cnt=cnt&a[j];
                }
            }
            sum=max(sum,cnt);
        }
        cout<<sum;
    }
    return 0;
}
