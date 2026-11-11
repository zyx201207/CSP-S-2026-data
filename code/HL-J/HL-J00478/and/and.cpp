#include<bits/stdc++.h>
using namespace std;
int n,m,ma=0;
int ar[500000]={0};
int aa(int s,int a,int b)
{
    if(b==1)
    {
        for(int i=a;i<n;i++)
        {
            ma=max(ma,s&ar[i]);
        }
        return 0;
    }
    else
    {
        for(int i=a;i<n;i++)
        {
            aa(s&ar[i],i+1,b-1);
        }
    }
    return 0;
}
int main()
{
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%d",&ar[i]);
    if(m==1)
    {
        int b=0;
        for(int i=0;i<n;i++)
        {
            b=max(ar[i],b);
        }
        cout<<b;
        return 0;
    }
    else if(m==2)
    {
        int b=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {

                b=max(b,ar[i]&ar[j]);
            }
        }
        cout<<b;
        return 0;
    }
    else if(m==n-1)
    {
        int b=0;
        for(int i=0;i<n;i++)
        {
            int s;
            if(i==0)s=ar[1];
            else s=ar[0];
            for(int j=1;j<n;j++)
            {
                if(j!=i)
                {
                    s&=ar[j];
                }
            }
            b=max(b,s);
        }
        cout<<b;
        return 0;
    }
    else if(m==n)
    {
        int b=ar[0];
        for(int i=1;i<n;i++)
        {
            b&=ar[i];
        }
        cout<<b;
        return 0;
    }
    aa(1024*1024-1,0,m);
    cout<<ma;
    return 0;
}
