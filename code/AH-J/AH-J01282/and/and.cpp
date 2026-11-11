#include<bits/stdc++.h>
using namespace std;
#define itn int
#define ll long long
int n,m;
int ans=0;
int x[200005];
int f[200005];
int maxx=-0x3f3f3f3f;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i],maxx=max(maxx,x[i]);
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
//	sort(x+1,x+n+1);
	for(int i=n;i>=1;i--)
//		for(int j=m;j>=1;j--)
			f[i]=max(f[i],f[i-1]|x[i]);
	cout<<f[n];

	return 0;
}

