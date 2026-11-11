#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e4+5,M=5e2+5;
int c,n,m,d,q,w[N],k[M],a[M][N],t[M][N],s,tt;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	while(q--)
	{
		int ans=0,ids=0,idt=0;
		bool f=false;
		cin>>s>>tt;
		ans+=(w[s]+w[tt]);
		for(int i=1;i<=n;i++)
		{
			ids=0,idt=0;
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]==s)
					ids=i;
				if(a[i][j]==tt)
					idt=i;
			}
			if(ids!=0&&idt!=0)
			{
				ans+=(t[ids][1]+t[idt][2]);
				cout<<ans<<endl;
				f=true;
			}
		}
		if(f)
			continue;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]==s)
					ids=i;
				if(a[i][j]==tt)
					idt=i;
			}
		ans+=(t[ids][1]+t[idt][2]);
		cout<<ans<<endl;
	}
	return 0;
}
