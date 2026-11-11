#include <bits/stdc++.h>

using namespace std;
long long s[200100]= {0};
long long f=-1;
long long bejz(long long a)
{
    long long n=1;
    while (a!=1)
    {
        if(a%2==0)
        {
            a/=2;
            n*=10;
        }
        else
        {
            a=(a-1)/2;
            n=n*10+1;
        }
    }
    return n;
}
long long an(long long a,long long b)
{
    long long n=1;
    if(a>b)
    {
        while (b!=1)
        {
            if(a%10==b%10)
            {
                n=n*10;
                a/=10;
                b/=10;
            }
        }
        return n;
    }
}
long long bh(long long a)
{
    long long n=0;
    int d=0;
        while (a!=1)
        {
            if(a%10==1)
            {
                n+=pow(2,d);
                a/=10;
            }
        }
        return n;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,w;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        long long q;
        cin>>s[i];
        //s[i]=bejz(q);cout << s[i]<<endl;
    }
    sort(s,s+n,greater<int>());
    /*for(int j=0; j<m; j++)
    {

    }
    /*f=bh(f);
    cout << f;*/
    cout<<s[m-1];
    return 0;
}
