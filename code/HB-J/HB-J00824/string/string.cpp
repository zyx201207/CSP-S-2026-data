#include <bits/stdc++.h>
using namespace std;
long long n;
long long needn=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    long long arr_n[n+100];
    char arr_c[n+100];
    long long maxn=0;
    for(long long i=0;i<n;i++)
    {
        cin>>arr_n[i]>>arr_c[i];
        if(arr_n[i]>maxn)
        {
            maxn=arr_n[i];
        }
    }
    char s[maxn*n+100];
    long long g=0;

    for(long long i=0;i<n;i++)
    {
        for(long long m=0;m<arr_n[i];m++)
        {
            s[g]=arr_c[i];
            g++;
        }
    }
    long long num=g/2;
    for(long long i=0;i<num;i++)
    {
        if(s[i]==s[g-i-1])
        {
            continue;
        }else{
            needn++;
        }
    }
    cout<<needn;
    return 0;
}
