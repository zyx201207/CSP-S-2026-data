#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],l,r,sum[200005],ans;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum[i]=sum[i-1]+a[i];
    }
    l=1;
    r=n;
    for(long long i=1,j=sum[n];i<=j;)
    {
        long long add=min(sum[l]-i+1,j-sum[r-1]);
        //cout<<sum[l]<<' '<<i<<'\n';
        if(c[l]!=c[r])
        {
            ans+=add;
        }
        i+=add;
        j-=add;
        while(i>sum[l])l++;
        while(j<=sum[r-1])r--;
    }
    cout<<ans;




    return 0;
}
