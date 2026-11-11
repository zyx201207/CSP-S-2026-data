#include<bits/stdc++.h>
using namespace std;
long long n,m,l;
long long a[200003];
bool cmp(long long a,long long b)
{
    return a>b;
}
int cmp1(long long a,long long b)
{
    string z1,z2,z3;
    while(a!=0)
    {
        char o=a%2+'0';
        z1=o+z1;
        a/=2;
    }
    while(b!=0)
    {
        char o=b%2+'0';
        z2=o+z2;
        b/=2;
    }
    while(z1.size()!=z2.size())
    {
        if(z1.size()>z2.size()) z2='0'+z2;
        else z1='0'+z1;
    }
    long long c=z1.size();
    for(long long i=0;i<c;i++)
    {
        if(z1[i]=='0'||z2[i]=='0') z3+='0';
        else z3+='1';
    }
    long long m=0,s=0;
    for(long long i=z3.size()-1;i>=0;i--)
    {
        s=s+pow(2,i)*(z3[m]-'0');
        m++;
    }
    return s;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    l=a[1];
    for(long long i=2;i<=m;i++) l=cmp1(l,a[i]);
    cout<<l;
    return 0;
}
