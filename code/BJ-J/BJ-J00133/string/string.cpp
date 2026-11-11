#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long n,a[200005],ans=0,lst=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    lst=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=lst;j>=i;j--)
        {
            if(a[i]>=a[j])
            {
                if(c[i]!=c[j]) ans+=a[j];
                a[i]-=a[j];
                lst--;
                a[j]=0;
            }
            else
            {
                if(c[i]!=c[j]) ans+=a[i];
                a[j]-=a[i];
                a[i]=0;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
