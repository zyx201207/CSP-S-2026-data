#include<iostream>
using namespace std;
#define ll long long
struct pst{
    ll x;
    char c;
}a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].c;
    }
    ll l=1,r=n,ans=0;
    while(l<r)
    {
        if(a[l].c==a[r].c)
        {
            if(a[l].x>a[r].x)
            {
                a[l].x-=a[r].x;
                r--;
            }
            else if(a[r].x>a[l].x)
            {
                a[r].x-=a[l].x;
                l++;
            }
            else
            {
                l++,r--;
            }
        }
        else{
            if(a[l].x>a[r].x)
            {
                ans+=a[r].x;
                a[l].x-=a[r].x;
                r--;
            }
            else if(a[r].x>a[l].x)
            {
                ans+=a[l].x;
                a[r].x-=a[l].x;
                l++;
            }
            else{
                ans+=a[r].x;
                l++,r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
