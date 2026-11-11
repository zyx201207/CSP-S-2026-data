#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,num,a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=1,r;
    ans=num=1;
    long long u=0;
    for(r=2; r<=n; r++)
    {
        u+=num*(a[r]-a[r-1]);
        num+=1;
        while(u>m)
        {
            u-=(a[r]-a[l]);
            num--;
            l++;
        }
        ans=max(ans,num);
    }
    cout<<ans<<endl;
}
