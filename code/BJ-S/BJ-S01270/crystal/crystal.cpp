#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int t=n/2,p=m;
    while(P!=0)
    {
    	t--;
    	p=p-(a[n/2]-a[t]);
    }
    ans=n/2-t+1;
    cout<<ans;
    return 0;
}