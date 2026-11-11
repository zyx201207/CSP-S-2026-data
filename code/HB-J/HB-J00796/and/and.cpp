#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[200010];
int maxn=-100000;
int sum=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sum=a[1];
    for(int i=2;i<=n;i++)
    {
        sum&=a[i];
    }
    if(m==1) cout<<maxn;
    else if(m==n) cout<<sum;
    else if(m==2)
    {
        int maxnn=-1000;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j==i) continue;
                maxnn=max(maxnn,a[i]&a[j]);
            }
        }
        cout<<maxnn;
    }
    else if(m==n-1)
    {
        int maxxn=-1000;
        int num=0;
        for(int i=1;i<=n;i++)
        {
            num=a[i+1];
            for(int j=i+2;j<=n;j++)
            {
                num&=a[j];
            }
            maxxn=max(maxxn,num);
        }
        cout<<maxxn;
    }
    return 0;
}
