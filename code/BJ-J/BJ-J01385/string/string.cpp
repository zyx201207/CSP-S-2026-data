#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,s;
    string a;
    char b;
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>s>>b;
        for (long long i=0;i<s;i++)
        {
            a=a+b;
        }
    }
    long long l=0,r=a.length()-1,sum=0;
    while (l<r)
    {
        if (a[l]!=a[r])
        {
            sum++;
        }
        l++;
        r--;
    }
    cout<<sum;
    return 0;
}