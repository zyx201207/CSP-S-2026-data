#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e5+5;
int n,m,a[M],ans=-1;
int vis[M],ans2;
bool cmp(int a1,int a2)
{
	return a1>a2;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for (int i=32; i>=0; i--)
	{
		vector<int> b;
		int count=0,res=-1;
		for (int j=1; j<=n; j++)
		{
			if ((a[j]&(1LL<<i))==(1LL<<i))
			{
				count++;
				if (count<=m)
				{
					if (res==-1) res=a[j];
					else res&=a[j];
					vis[j]++;
					b.push_back(j);
				}
			}
			else if (vis[j])
			{
				count=-1;
				break;
			}
		}
		if (count>=m)
		{
			if (ans==-1) ans=res;
			else ans&=res;
			ans2=max(ans,res);
		}
		else
		{
			for (int j=0; j<b.size(); j++)
			{
				vis[b[j]]--;
			}
		}
	}
	cout<<max(ans2,ans);
	return 0;
}
