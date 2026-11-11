#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long n;
long long a[maxn];
char c[maxn];
string s;
int cnt=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    long long len=s.length();
    long long l=0, r=len-1;
    if(len%2==0)
    {
        while(l<=r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                cnt++;
                l++;
                r--;
            }
        }
    }
    else
    {
        long long mid=(len-1)/2;
        while(l<=mid&&r>=mid)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                cnt++;
                l++;
                r--;
            }
        }
    }
    cout << cnt;
    return 0;
}