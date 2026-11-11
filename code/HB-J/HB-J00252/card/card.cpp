#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[6005],ans[4005],sum[6005],t;
int check(int h)
{
    for(int i=1;i<=n;i++)
    {
        if(sum[i]==h){return i;}
    }
    return -1;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        t=1;
        for(int j=i;j<=n;j++)
        {
            if(check(a[j])==-1)
            {
                sum[t]=a[j];
                t++;
            }
            else
            {
                t=check(a[j]);
                int s=t;
                while (sum[s]!=0){sum[s]=0;s++;}
                sum[t]=a[j];
                t++;
            }
        }
        while(t>1)
        {
            t--;
            ans[sum[t]]+=1;
            sum[t]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
