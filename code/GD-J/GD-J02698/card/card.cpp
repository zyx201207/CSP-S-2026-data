#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5,N=5e5+5;
vector<int> biao[M];
int a[N];
long long cnt[M],ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		++cnt[a[i]];
	}
	int cnt2=0;
	for(int i=n;i>0;--i)
	{
		if(biao[a[i]].empty())
		{
			biao[a[i]]=biao[a[i+1]];
			biao[a[i]].push_back(a[i]);
			++cnt2;
		}
		if(cnt2==m)
		{
			break;
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<biao[i].size();++j)
		{
			ans[biao[i][j]]+=cnt[i];
		}
	}
	for(int i=1;i<=m;++i)
	{
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
