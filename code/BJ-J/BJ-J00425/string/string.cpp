#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long a[maxn];
char c[maxn];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r)
    {
        if(a[l]>a[r])
        {
            if(c[l]!=c[r])
            {
                ans+=a[r];
            }
            a[l]-=a[r];
            r--;
            continue;
        }
        else if(a[r]>a[l])
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            a[r]-=a[l];
            l++;
            continue;
        }
        else
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            r--;
            l++;
            continue;
        }
    }
    cout<<ans;
    return 0;
}
