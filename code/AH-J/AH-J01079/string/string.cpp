#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char s[200010];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
    }
    long long ans=0;
    long long l=1,r;
    r=n;
    while(l<r)
    {
        if(a[l]>a[r])
        {
            if(s[r]!=s[l])
            {
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
            else
            {
                a[l]-=a[r];
                r--;
            }
        }
        if(a[l]<a[r])
        {
            if(s[r]!=s[l])
            {
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }
            else
            {
                a[r]-=a[l];
                l++;
            }
        }
        if(a[l]==a[r])
        {
           if(s[l]!=s[r])
           {
               ans+=a[l];
               l++;
               r--;
           }
           else
           {
               l++;
               r--;
           }
        }
    }
    cout<<ans;
    return 0;
}
