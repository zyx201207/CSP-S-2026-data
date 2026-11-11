#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll a[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }

    int l=1,r=n;
    while(l<r)
    {
        if(c[l]!=c[r])
        {
            if(a[l]>a[r])
            {
                ans+=a[r];
                a[l]-=a[r];
                 r--;
            }
            else if(a[l]==a[r])
            {
                ans+=a[r];
                l++;
                r--;
            }
            else
            {
                ans+=a[l];
                a[r]-=a[l];
                l++;

            }
            //for(int i=1;i<=n;i++) cout<<a[i]<<" ";
            //cout<<'\n';
        }
        else
        {
            if(a[l]>a[r])
            {
                a[l]-=a[r];
                r--;
            }
            else if(a[l]==a[r]) l++,r--;
            else{
                a[r]-=a[l];
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
