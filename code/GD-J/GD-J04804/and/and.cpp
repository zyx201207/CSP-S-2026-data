#include<bits/stdc++.h>
using namespace std;
int a[200010];	
int top=0;
vector<int>m[32];
priority_queue<int,vector<int> >q;
void check()
{
	if(m[top].size()==1)
	{
		int x=m[top][0];
		q.pop();
		x-=pow(2,top);
		q.push(x);
		for(int j=1;j<=30;j++)
		{
			if(x<pow(2,j))
			{
				m[j-1].push_back(x);
				break;
			}
		}
		while(--top)
		{
			if(m[top].size())
			{
				check();
				return ;
			}
		}
	} 
}
int main()
{
	freopen("and1.in","r",stdin);
	freopen("and1.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		q.push(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=30;j++)
		{
			if(a[i]<pow(2,j))
			{
				m[j-1].push_back(a[i]);
				top=max(top,j-1);
				break;
			}
		}
	}
	check();
	int ans=q.top();
	q.pop();
	for(int i=2;i<=k;i++)
	{	
		for(int j=1;j<=30;j++)
		{
			if(ans<pow(2,j))
			{
				top=j-1;
				break;
			}
		}
		int mod=pow(2,top+1);
		while(q.top()>=mod)
		{
			int x=q.top();
			q.pop();
			x%=mod;
			q.push(x);
		}
		ans=ans&q.top();
		q.pop();
	}
	cout<<ans;
	return 0;
}
