#include <bits/stdc++.h>
using namespace std;
int n;
long long sum;
struct node{
    int s;
    char c;
}a[200005];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].s>>a[i].c;
        sum+=a[i].s;
        for (int j=1;j<=a[i].s;j++)
        {
            s+=a[i].c;
        }
    }
    long long mid=(sum+1)/2;
    long long ans=0;
    for (int i=mid-1;i>=0;i--)
    {
        if (s[i]!=s[sum-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
