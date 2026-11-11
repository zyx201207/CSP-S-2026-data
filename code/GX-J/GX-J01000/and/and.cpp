#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s[200001];
long long a[100000000];
string f(long long a)
{
    string as;
    for(int i=31;i>=0;i--)
    {
        if(a>=(pow(2,i)))
        {
            a-=pow(2,i);
            as+='1';
        }
        else as+='0';
    }
    return as;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        long long k;
        cin>>k;
        s[i]=f(k);
        a[k]++;
    }
    long long g=0,maxn=0;
    for(long long i=1;i<=100000000;i++)
    {
        if(a[i]>=maxn)
        {
            g=i;
            maxn=a[i];
        }
    }
    cout<<g;
    return 0;
}
