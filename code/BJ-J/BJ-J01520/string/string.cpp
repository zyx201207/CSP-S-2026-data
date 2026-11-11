#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    ll sum=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    sum/=2;
    ll i=1,idx1=1,idx2=n;
    while(i<=sum)
    {
        if(a[idx1]>a[idx2])
        {
            if(c[idx1]==c[idx2])
            {
                i+=a[idx2];
                a[idx1]-=a[idx2];
                idx2--;
            }
            else
            {
                i+=a[idx2];
                a[idx1]-=a[idx2];
                ans+=a[idx2];
                idx2--;
            }

        }
        else if(a[idx1]<a[idx2])
        {
            if(c[idx1]==c[idx2])
            {
                i+=a[idx1];
                a[idx2]-=a[idx1];
                idx1++;
            }
            else
            {
                i+=a[idx1];
                a[idx2]-=a[idx1];
                ans+=a[idx1];
                idx1++;
            }
        }
        else
        {
            if(c[idx1]==c[idx2])
            {
                i+=a[idx1];
                idx1++;
                idx2--;
            }
            else
            {
                i+=a[idx1];
                ans+=a[idx1];
                idx1++;
                idx2--;
            }
        }
    }
    cout<<ans;
    return 0;
}
