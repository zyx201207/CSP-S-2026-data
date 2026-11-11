#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int g(int n,int m)
{
    int num=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        int s=m;
        sum=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]<a[i]&&s+a[j]>=a[i])
            {
                s-=a[j];
                sum++;
            }
            if(a[j]==a[i])
            {
                sum++;
            }
        }
        if(sum>num)
        {
            num=sum;
        }
    }
    return num;
};
int main()
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<g(n,m);
    return 0;
}
