#include <bits/stdc++.h>
using namespace std;
long long n,a[2000005],ans;
char c[2000005];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<=r)
    {
        ans+=(c[l]!=c[r])*min(a[l],a[r]);
        if(a[l]<a[r])
        {
            a[r]-=a[l];
            l++;
        }
        else if(a[l]==a[r])
        {
            l++;
            r--;
        }
        else
        {
        a[l]-=a[r];
            r--;
        }
        //cout<<l<<" "<<r<<" "<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}
