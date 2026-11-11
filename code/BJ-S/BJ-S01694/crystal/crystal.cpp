#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
int ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    __int128 sum=0;
    for(int l=1,r=1;r<=n;)
    {
        while(sum>m&&l<=r)
        {
            sum-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
        r++;
        sum+=__int128(a[r]-a[r-1])*(r-l);
    }
    cout<<ans<<endl;
    return 0;

}