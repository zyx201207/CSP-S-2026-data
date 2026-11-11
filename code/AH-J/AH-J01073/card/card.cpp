#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],b[M],c[N],sta[N],top,fl,dp[N];
signed main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    if(m==1)
    {
		cout<<n;
		return 0;
	}
    for(int i=1;i<=n;i++)
        cin>>a[i],fl=(fl?1:(a[i-1]>a[i]));
    if(!fl)
    {
		for(int i=1;i<=n;i++)
			ans[a[i]]=i;
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
		return 0;
	}
	if(n<=5000)
	{
		for(int k=1;k<=n;k++)
		{
			for(int i=k;i<=n;i++)
			{
				if(b[a[i]])
					for(int j=b[a[i]];j<i;j++)
						b[a[j]]=0;
				b[a[i]]=i;
			}
			for(int i=1;i<=m;i++)if(b[i])ans[i]++,b[i]=0;
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
		return 0;
	}
    for(int i=n;i>=1;i--)
    {
        if(b[a[i]])c[i]=b[a[i]];
        b[a[i]]=i;
    }
    for(int i=1;i<=m;i++)b[i]=0;
    for(int i=1;i<=n;i++)
    {
        while(top&&c[sta[top]]<=i)top--;
//        cout<<(top?sta[top]:0)<<' ';
		ans[a[i]]=i-sta[top]+(top>0)*b[a[i]];
//		b[a[i]]+=(c[sta[top]]-sta[top]);
        sta[++top]=i;
        b[a[i]]+=(i-sta[top-1]);
//       cout<<ans[a[i]]<<'\n';
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}
