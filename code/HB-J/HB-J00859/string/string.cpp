#include<bits/stdc++.h>
using namespace std;
long long n,sum,res;
long long a[100000000];
char b[100000000],c[100000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<n;i++)
    {
        cin>>a[i]>>b[i];
        for(int j=sum+1;j<=a[i]+sum;j++)
        {
            c[j]=b[i];
        }
        sum+=a[i];
    }
    long long num=sum+1;
    if(sum%2==1)
    {
        for(long long i=1,j=sum;i<=sum/2,j>num/2;i++,j--)
        {
            if(c[i]!=c[j]) res++;
        }
    }
    else
    {
        for(long long i=1,j=sum;i<=sum/2,j>sum/2;i++,j--)
        {
            if(c[i]!=c[j]) res++;
        }
    }
    cout<<res;
    return 0;
}
