#include<bits/stdc++.h>
using namespace std;
int a[5000005]={0},b[5000005]={0},mn[3000005]={0};
int many(int m)
{
    int n=0;
    for(int i=0;i<m;i++)
    {
        if(b[i]!=0)
        {
            n++;
        }
    }
    return n;
}
int too(int i,int j)
{
    for(int k=0;k<j;k++)
    {
        if(b[k]==i)
        {
            return j;
        }
    }
    return 0;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            b[j]=0;
        }
        for(int j=i;j<n;j++)
        {
            if(too(a[j],many(n))!=0)
            {
                for(int k=too(a[j],many(n));k<many(n);k++)
                {
                    b[k]=0;
                }
            }
            b[many(n)]=a[j];
        }
        for(int j=i;j<n;j++)
        {
            cout<<b[j]<<' ';
        }
        cout<<endl;
        for(int j=0;j<many(n);j++)
        {
            mn[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<mn[i]<<' ';
    }
    return 0;
}

