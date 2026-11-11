#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+2;
int c,n,m,d,q;
int k,x,y;
int w[N];
int a[N];
int t[N];
ll ans;
int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int mk=0;
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		mk=max(mk,k);
		for (int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j]; 
		}
	}
	sort(a+1,a+mk+1);
	sort(t+1,t+mk+1);
	mk=unique(a+1,a+mk+1)-a;
	for (int i=1;i<=q;i++)
	{
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		for (int j=1;j<=mk;j+=rand())
		{
			ans+=t[j];
			j-=1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
