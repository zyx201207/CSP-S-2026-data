#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int h[55];
int n,m;
vector<int> v,v2;
int lowbit(int x)
{
	return x&-x;
}
int shai()
{
	for (int i=0;i<=54;i++) h[i]=0;
	for (auto i:v)
	{
		int x=i;
		while (x)
		{
			h[(int)log2(lowbit(x))]++;
			x-=lowbit(x);
		}
	}
	int cnt=-1;
	for (int i=54;i>=0;i--)
	{
		if (h[i]>=m)
		{
			cnt=i;
			break;
		}
	}
	if (cnt==-1) return -1;
	for (auto i:v)
	{
		if (i&(1<<cnt))
		{
			v2.push_back(i-(1<<cnt));
		}
	}
	v.clear();
	for (auto i:v2)
	{
		v.push_back(i);
	}
	v2.clear();
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		v.push_back(a[i]);
	}
	int ans=0;
	while (1)
	{
		int sum=shai();
		if (sum==-1) break;
		else ans+=(1<<sum);
	}
	cout<<ans;
	return 0;
}
