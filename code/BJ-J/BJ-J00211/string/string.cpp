#include <iostream>
using namespace std;
string s=" ";
long long ans;
long long a[200005];
string q[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>q[i];
    }
    int l=1,r=n;
    for(int i=1;i<=n;i++)
    {
        if(l>=r) break;
        if(a[l]>a[r])
        {
            if(q[l]!=q[r])
            {
                ans+=a[r];
            }
            a[l]-=a[r];
            a[r]=0;
            r--;
        }
        if(a[l]<a[r])
        {
            if(q[l]!=q[r])
            {
                ans+=a[l];
            }
            a[r]-=a[l];
            a[l]=0;
            l++;
        }
        if(a[l]==a[r])
        {
            if(q[l]!=q[r])
            {
                ans+=a[r];
            }
            a[l]=0;
            a[r]=0;
            r--;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
