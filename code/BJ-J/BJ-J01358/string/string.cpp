#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[200005];
    char c[200005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int i=1,j=n,ans=0;
    while(i<j)
    {
        if(c[i]!=c[j])
        {
            ans+=min(a[i],a[j]);
            //cout<<ans<<endl;
            if(a[i]>a[j])
            {
                a[i]-=a[j];
                j--;
            }
            else if(a[i]<a[j])
            {
                a[j]-=a[i];
                i++;
            }
            else if(a[i]==a[j])
            {
                i++;
                j--;
            }
        }
        else
        {
            if(a[i]>a[j])
            {
                a[i]-=a[j];
                j--;
            }
            else if(a[i]<a[j])
            {
                a[j]-=a[i];
                i++;
            }
            else if(a[i]==a[j])
            {
                i++;
                j--;
            }
        }

    }
    cout<<ans;
    return 0;
}