#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
char c[200010];
signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    int ans=0;
    while(i<j)
    {
        if(c[i]!=c[j])
        {
            if(a[i]<a[j])
            {
                ans+=a[i];
                a[j]-=a[i];
                a[i]=0;
                i++;
            }
            else
            {
                ans+=a[j];
                a[i]-=a[j];
                a[j]=0;
                j--;
            }
        }
        else
        {
            if(a[i]<a[j])
            {
                a[j]-=a[i];
                a[i]=0;
                i++;
            }
            else
            {
                a[i]-=a[j];
                a[j]=0;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}