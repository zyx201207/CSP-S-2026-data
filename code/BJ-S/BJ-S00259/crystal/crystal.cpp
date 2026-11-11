#include <iostream>
#include <algorithm>
using namespace std;
int ca[500001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long cnt=0;
    int l=1,r=1;
    for(int i=1;i<=n;i++)
    {
        cin>>ca[i];
    }
    int ans=1;
    sort(ca+1,ca+n+1);
    while(r<=n)
    {
        if(cnt<=m)
        {
            if(ans<r-l+1)
            {
                ans=r-l+1;
            }
            if(r<n)
            {
                r++;
                cnt+=(r-l)*(ca[r]-ca[r-1]);
            }
            else
            {
                break;
            }
        }
        else
        {
            l++;
            cnt-=(ca[r]-ca[l-1]);
        }
    }
    cout<<ans;
}
