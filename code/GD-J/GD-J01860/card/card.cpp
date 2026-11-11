#include<bits/stdc++.h>
using namespace std;
#define rig register int
#define N 500005
int n,m,a[N],s[N];
main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(rig i=1;i<=n;i++) cin>>a[i];
	for(rig i=n;i;i--)
	{
		rig cnt=0,b[N];
		for(rig j=i;j<=n;j++)
		{
			b[++cnt]=a[j];
			for(rig k=cnt-1;k;k--)
				if(b[cnt]==b[k])
				{
					cnt=k;
					break;
				}
		}
		for(rig k=cnt;k;k--) s[b[k]]++;
	}
	for(rig i=1;i<=m;i++) cout<<s[i]<<' ';
}
