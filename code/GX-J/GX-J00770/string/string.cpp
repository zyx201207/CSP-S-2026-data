#include<bits/stdc++.h>
using namespace std;
struct st
{
    long long sl;
    char mz;
};
st a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].sl>>a[i].mz;
    }
    int l=1,r=n;
    while(l<=r)
    {
        if(a[l].mz!=a[r].mz)
        {
            if(a[l].sl==a[r].sl)
            {
                cnt+=a[l].sl;
                l++;
                r--;
            }
            else if(a[l].sl>a[r].sl)
            {
                a[l].sl-=a[r].sl;
                cnt+=a[r].sl;
                r--;
            }
            else
            {
                a[r].sl-=a[l].sl;
                cnt+=a[l].sl;
                l++;
            }
        }
        else
        {
            if(a[l].sl==a[r].sl)
            {
                l++;
                r--;
            }
            else if(a[l].sl>a[r].sl)
            {
                a[l].sl-=a[r].sl;
                r--;
            }
            else
            {
                a[r].sl-=a[l].sl;
                l++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
