#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
deque<int> q;
int ans[500005];
void solve(int j)
{
	int p=0;
	if(q.empty()||find(q.begin(),q.end(),a[j])==q.end())
	{
		q.push_back(a[j]);
		return ;
	}
	for(int l=0;l<q.size();++l)
	{
		if(q[l]==a[j])
		{
			p=l;
			break;
		}
	}
	q.erase(q.begin()+p,q.end());
	q.push_back(a[j]);
}
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			solve(j);
		}
		for(int j=0;j<q.size();++j)
		{
			++ans[q[j]];
		}
		q.clear();
	}
	for(int i=1;i<=m;++i)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
} 
