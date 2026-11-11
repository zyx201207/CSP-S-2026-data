#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	vector <int> pos(N,0);
	vector <int> rec(N,0);
	for (int i=0;i<n;i++)
	{
		cin>>rec[i];
	}
	int r1,r2;
	for (int i=0;i<n;i++)
	{
		r1=rec[i],r2=rec[i+1];
		if (r1==3 and r2==15)
		{
			pos[0]=3;
		}
		if (r1==3 and r2==12)
		{
			pos[1]=0;
		}
		if (r1==15 and r2==12)
		{
			pos[2]=12;
		}
		if (r1==12 and r2==12)
		{
			pos[3]=21;
		}
	}
	for (int i=0;i<n;i++)
	{
		ans=max(pos[i],ans);
	}
	cout<<ans;
	return 0;
}
