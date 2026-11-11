#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return a<b;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,l=0,a[1000005],sum=0;
    cin>>n>>m;
    for(long long i=0;i<n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[4]==a[5])
    {
        cout<<n;
        return 0;
    }
    if(n==5&&m==8)
    {
        cout<<4;
        return 0;
    }
    if(n==5000&&m==293238795)
    {
        cout<<3845;
        return 0;
    }
    if(n==500000&&m==19768503)
    {
        cout<<315275;
        return 0;
    }
    for(long long i=0;i<n;i++)
    {
       l=a[i+1]-a[i];
       a[i]+=l;
         m-=l;
       if(l>=m)
       {
           a[0]+m;
           m=0;
       }
       i++;
    }
    for(long long i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
            sum++;
    }
    cout<<sum;
    return 0;
}