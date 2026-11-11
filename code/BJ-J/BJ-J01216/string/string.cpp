#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    int n,y=1,zong=0,ans=0;
    cin>>n;
    string a[100000],b[100000];
    for(int i=1;i<=n;i++)
    {
        int x=1;
        string z;
        cin>>x>>z;

        for(int j=y;j<=y+x-1;j++)
        {
            a[j]=z;
        }
        y=y+x;
        zong+=x;

    }
    if(zong%2==0)
    {

        for(int i=1;i<=zong/2;i++)
        {

            b[i]=a[i];
        }
        for(int i=zong/2+1;i<=zong;i++)
        {

            b[i]=a[zong-i+1];
        }
        for(int j=zong/2+1;j<=zong;j++)
        {
            if(b[j]!=a[j])
            {

                ans++;
            }

        }
    }
    if(zong%2==1)
    {

        for(int i=1;i<=zong/2+1;i++)
        {

            b[i]=a[i];
        }
        for(int i=zong/2+2;i<=zong;i++)
        {

            b[i]=a[zong-i+1];
        }
        for(int j=zong/2+2;j<=zong;j++)
        {
            if(b[j]!=a[j])
            {

                ans++;
            }

        }
    }
cout<<ans;
}
