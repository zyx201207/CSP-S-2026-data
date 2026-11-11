#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[200005],s=2147483647,ans,t;
bool f1=1,fa=1,fb=1;
int sm(int x)
{
    int c=0,sum=2147483647;
    for(int i=0;i<n;i++)
    {
        if(x&(1<<i))
        {
            c++;
            sum&=a[i];
        }
    }
    if(c!=m)
    {
        return 0;
    }
    return sum;
}
bool c(int x)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if((x&a[i])==x)
        {
            c++;
        }
    }
    return c>=m;
}
int main()//75~85pts
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    t=n;
    while(t>1)
    {
        if(t&1)
        {
            fb=0;
            break;
        }
        else
        {
            t>>=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>1024)
        {
            f1=0;
        }
        if(a[i]!=i)
        {
            fb=0;
        }
        ans=max(ans,a[i]);//5pts
        s&=a[i];
    }
    if(n<=20)//25pts
    {
        ans=0;
        for(int i=1;i<(1<<n);i++)
        {
            ans=max(ans,sm(i));
        }
    }
    else if(m==n)//5pts
    {
        ans=s;
    }
    else if(f1)//10~20 pts
    {
        for(int i=ans;i>=1;i--)
        {
            if(c(i))
            {
                ans=i;
                break;
            }
        }
    }
    else if(fb)//10pts
    {
        ans=n-1;
        t=1;
        while(t<m)
        {
            ans-=t;
            t<<=1;
        }
    }
    else if(m==2&&n<=2000)//15pts
    {
        ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else if(m>1)//5pts
    {
        sort(a,a+n,greater<int>());
        ans=a[m-1];
    }
    cout<<ans;
    return 0;
}
