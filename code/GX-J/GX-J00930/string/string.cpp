#include<bits/stdc++.h>
using namespace std;
long long a[200002],l,r,ans,n;
char s[200002];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    l=1,r=n;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i]>>s[i];
    }
    while(l<=r)
    {
        if(a[l]<a[r])
        {
            if(s[l]!=s[r])
                ans+=a[l];
            a[r]-=a[l];
            a[l]=0;
        }
        else
        {
            if(s[l]!=s[r])
                ans+=a[r];
            a[l]-=a[r];
            a[r]=0;
        }
        if(a[l]==0)
            l++;
        if(a[r]==0)
            r--;
    }
    cout<<ans;
    return 0;
}

