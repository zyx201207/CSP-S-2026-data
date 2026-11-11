//T3
#include <bits/stdc++.h>
using namespace std;
int a[200001],ans,n,m;
//不是？我记得有一场你古月赛的题跟着一模一样阿？这还是个弱化版O(n*logn*logn)都能过
//666这期神了，你古的朋友们可以找找原题，我记得有
//不会出原题吧？
//这不就原题吗？
bool check2(int x)
{
	if(ans==0)
	{
		return 1;
	}
	for(int i=0;i<=30;++i)
	{
		if(((ans>>i)&1)&&!((x>>i)&1))
		{
			return 0;
		}
	}
	return 1;
}
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(((a[i]>>x)&1)&&check2(a[i]))
		{
			cnt++;
		}
		if(cnt>=m)
		{
			return 1;
		}
	}
	return 0;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int mask=30;mask>=0;--mask)
	{
		if(check(mask))
		{
			ans|=(1<<mask);
		}
	}
	cout<<ans;
	return 0;
}