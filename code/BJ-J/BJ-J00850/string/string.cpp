#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l=1,r;
long long ans;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    r=n;
    while(l<r)
    {
        if(a[l]<a[r])
        {
            a[r]-=a[l];
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            l++;
        }
        else if(a[l]>a[r])
        {
            a[l]-=a[r];
            if(c[l]!=c[r])
            {
                ans+=a[r];
            }
            r--;
        }
        else
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
