#include<iostream>
using namespace std;
typedef long long ll;
const int N=2e5+7;
int n,a[N];
char c[N];
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
    ll ans=0;
    while(l<r)
    {
        if(a[l]>a[r])
        {
            if(c[l]!=c[r])
            {
                ans+=a[r];
            }
            a[l]-=a[r];
            r-=1;
        }
        else if(a[l]==a[r])
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            l+=1;
            r-=1;
        }
        else
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            a[r]-=a[l];
            l+=1;
        }
    }
    cout<<ans;
    return 0;
}