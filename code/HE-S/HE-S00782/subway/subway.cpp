#include<bits/stdc++.h>
using namespace std;
long long cnt,ans,c,n,m,d,p,a[10010],aa[10010],b[10010][10010],c[10010][10010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
		for(int j=1;j<=aa[i];j++)
		{
			cin>>b[i][j]>>c[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
        cin>>x>>y;
        ans+=a[x]+a[y];
        cout<<ans<<endl;
        ans=0;
	}
	return 0;
}
