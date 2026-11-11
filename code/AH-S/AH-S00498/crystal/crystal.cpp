#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans,t,h=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(long long i=1;i<=n;i++)
    {
        t=a[i]*(i-h)-s[i-1]+s[h-1];
        if(t<=m)ans=max(ans,i-h+1);
        else
        {
            while(1)
            {
                h++;
                t=a[i]*(i-h)-s[i-1]+s[h-1];
                if(t<=m)break;
            }
            ans=max(ans,i-h+1);
        }
    }
    cout<<ans;
	return 0;
}
