#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,num=0,cnt=0;
    cin >> n;
    long long a[n];
    char b[n];
    for(long long i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        num += a[i];
    }
    char s[num]={0};
    long long sum=0;
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<a[i];j++)
        {
            s[sum] = b[i];
            sum++;
        }
    }
    long long l=0;
    long long r=num-1;
    for(long long i=0;i<(num/2);i++)
    {
        if(s[l]!=s[r])
        {
            cnt++;
        }
        l++;
        r--;
    }
    cout << cnt;
    return 0;
}