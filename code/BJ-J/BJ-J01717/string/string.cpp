#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r)
    {
      //  cout<<ans<<" "<<l<<" "<<r<<"\n";
        if(b[l]!=b[r])
        {
            ans+=min(a[l],a[r]);
        }
        if(a[l]==a[r])
        {
            l++,r--;
        }
        else if(a[l]<a[r])
        {
            a[r]-=a[l];
            l++;
        }
        else if(a[l]>a[r])
        {
            a[l]-=a[r];
            r--;
        }
       // cout<<ans<<" "<<l<<" "<<r<<"\n";
    }
    cout<<ans;
    return 0;
}
