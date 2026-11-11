#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1234567],ans=-12345678,l=1,r=2,sum=0,s[1234567],x=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    for(int i=2;i<=n;i++)
        s[i]=a[i-1]-a[i];
    while(r<=n)
    {
        if(!x)
            sum+=a[l]-a[r];
        if(l==r)
            r++;
        else if(sum>m)
        {
            l++;
            sum-=s[l]*(r-l+1);
            x=1;

        }
        else
        {
            r++;
            x=0;
        }
        ans=max(r-l,ans);

    }
    cout<<ans;
	return 0;
}
