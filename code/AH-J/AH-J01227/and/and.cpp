#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=INT_MIN,a[200005],s[200005];
stack<int> q;
void dfs(int step,int cnt)
{
	if(cnt==m)
	{
		memset(s,0,sizeof(s));
		int id=0,t;
		t=q.top();
		s[++id]=q.top();
		q.pop();
		while(!q.empty())
		{
			s[++id]=q.top();
			t&=q.top();
			q.pop();
		}
		for(int i=1;i<=id;i++)
			q.push(s[i]);
		maxn=max(maxn,t);
		return;
	}
	if(step>n) return;
	dfs(step+1,cnt);
	q.push(a[step]);
	dfs(step+1,cnt+1);
	q.pop();
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0);
	cout<<maxn;
	return 0;
}
