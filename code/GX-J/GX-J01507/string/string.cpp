#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0;
    cin>>n;
    string s1;
    long long a[n+1]={0},k=0;
    char c[n+1]={0};
    for(long long i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<a[i];j++)
        {
            s1[k]=c[i];
            k++;
        }
    }
    long long y=k-1;
    k=0;
    if((y+1)%2!=0)
        sum--;
    for(long long i=0;i<=n;i++)
    {
        if(s1[k]!=s1[y-i])
        {
            sum++;
            k++;
        }
    }
    cout<<sum;
    return 0;
}
