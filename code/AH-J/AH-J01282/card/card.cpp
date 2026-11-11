#include<bits/stdc++.h>
using namespace std;
#define itn int
#define ll long long
int n,m;
itn ds[500005];
int ans[300005];
int flag[300005];
bool isit[300005];
stack<int> q;
stack<int> head;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>ds[i];
	for(int i=1;i<=n;i++)
		ans[ds[i]]=flag[ds[i]]=i;
	q.push(ds[n]);
	isit[ds[n]]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(isit[ds[i]])
		{
			while(q.top()!=ds[i] && !q.empty())
				/*head.push(q.top()),*/ans[q.top()]-=i,isit[q.top()]=0,q.pop();
		}
		else
			q.push(ds[i]),isit[ds[i]]=1;
	}
	for(int i=1;i<=m;i++)
		cout<<((ans[i]<0)?(ans[i]+flag[i]):(ans[i]))<<" ";

	return 0;
}


