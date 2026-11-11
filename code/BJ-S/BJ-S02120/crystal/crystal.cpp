#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],c[10],h[100],ans,n,m,cnt=0;
void sol1(int n1,int m1)
{
    if(m1==0||n1==0)
    {
        for(int i=0;i<100;i++)
        {
            h[i]=0;
        }
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            h[a[i]+c[i]+20]++;
            maxx=max(maxx,h[a[i]+c[i]+20]);
        }
        ans=max(maxx,ans);
        return ;
    }
    n1--;
    for(int i=0;i<=m1;i++)
    {
        c[n1]=i;
        sol1(n1,m1-i);
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=5000)
    {
        sol1(n,m);
        cout<<ans;
    }
    else if(n<=500000)
    {
		for(int i=n;i>=1;i--)
		{
			m-=a[n]-a[i];
			if(m<0)
			{
				break;
			}
			cnt++;
		}
		cout<<cnt;
	}
    return 0;
}
/*
        */
