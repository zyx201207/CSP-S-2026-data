#include<bits/stdc++.h>
using namespace std;
long long a[222222];
long long power2(long long n)//2^
{
    long long s=1;
    for(long long i=1;i<=n;i++)
        s*=2;
    return s;
}
string fun2(long long a)//long long->string    10->2
{
    string s1="";
    while(a>0)
    {
        s1+=char(a%2+'0');
        a/=2;
    }
    string s2="";
    long long l=s1.size();
    for(long long i=l-1;i>=0;i--)
        s2+=s1[i];
    return s2;
}
long long fun1(long long a,long long b)//and    10->2   2->10
{
    string s1=fun2(a),s2=fun2(b);
    long long l1,l2;
    l1=s1.size();
    l2=s2.size();
    if(l1<l2)
    {
        string ss;
        ss=s1;
        s1=s2;
        s2=ss;
        l1=s1.size();
        l2=s2.size();
    }
    if(l1>l2)
    {
        for(;l1>l2;l2++)
            s2='0'+s2;
    }
    string s="";
    for(long long i=0;i<l1;i++)
    {
        if(s1[i]=='1'&&s2[i]=='1')
            s+='1';
        else
            s+='0';
    }
    long long c=0;
    for(long long i=l1-1;i>=0;i--)
        c+=(s[i]-'0')*power2(l1-i-1);
    return c;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    bool ssr=1;
    long long ur=a[1];
    for(long long i=1;i<=n;i++)
        if(ur!=a[i])
            ssr=0;
    if(ssr)
    {
        cout<<ur<<endl;
        return 0;
    }
    if(m==1)
    {
        long long max0=0;
        for(long long i=1;i<=n;i++)
            if(max0<=a[i])
                max0=a[i];
        cout<<max0<<endl;
        return 0;
    }
    if(m==2)
    {
        long long max0=0;
        for(long long i=1;i<=n;i++)
            for(long long j=i+1;j<=n;j++)
            {
                long long s=fun1(a[i],a[j]);
                if(s>max0)
                    max0=s;
            }
        cout<<max0<<endl;
        return 0;
    }
    if(m==n-1)
    {
        long long s=a[1];
        for(long long i=2;i<n;i++)
            s=fun1(s,a[i]);
        long long max0=s;
        for(long long i=1;i<n;i++)
        {
            s=a[i+1];
            for(long long j=1;j<=n;j++)
            {
                if(j==i||j==i+1)
                    continue;
                s=fun1(s,a[j]);
            }
            if(s>max0)
                max0=s;
        }
        cout<<max0<<endl;
        return 0;
    }
    if(m==n)
    {
        long long s=a[1];
        for(long long i=2;i<=n;i++)
            s=fun1(s,a[i]);
        cout<<s<<endl;
        return 0;
    }
    long long s=a[1];
    for(long long i=m+1;i<n;i++)
        s=fun1(s,a[i]);
    long long max0=s;
    for(long long i=1;i<n;i++)
    {
        s=a[i+1];
        for(long long j=1;j<=n;j++)
        {
            bool k=0;
            for(long long sr=i;sr<=i+m;sr+=1)
                if(sr==j)
                    k=1;
            if(k)
                continue;
            s=fun1(s,a[j]);
        }
        if(s>max0)
            max0=s;
    }
    cout<<max0<<endl;
    return 0;
}
