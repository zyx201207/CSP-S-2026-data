#include <bits/stdc++.h>
using namespace std;
const int N=2e5+15;
long long n,sum[N],ans=0;
long long a[N],b[N];
string s;
int len(int d)
{
    if(d<sum[0])
    {
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        if(d>=sum[i-1] && d<sum[i])
        {
            return i;
        }
    }
    return -1;
}
int dis()
{
    long long cnt=0;
    for(unsigned long long i=0;i<ans/2;i++)
    {
        if(s[len(i)]!=s[len(ans-i-1)])
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>s[i];
        ans+=a[i];
        sum[i]=sum[i-1]+a[i];
    
    }
    sum[0]=a[0];
    cout<<dis();
    return 0;
}