#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<map>
using namespace std;
int n,m;
int a[200000+10];
bool cmp(int x,int y)
{
	return x>y;
}
stack<int>q,p;
void sp(int k)
{
	long long cnt=1073741824;
	//cout<<endl<<k<<"       ";
	while(cnt!=0)
	{
		if(cnt<=k)
		{
			p.push(cnt);
			//cout<<cnt<<" ";
			k-=cnt;
		}
		cnt/=2;
	}
	return ;
}
void sq(int k)
{
	long long cnt=1073741824;
	//cout<<endl<<k<<"       ";
	while(cnt!=0)
	{
		if(cnt<=k)
		{
			q.push(cnt);
			//cout<<cnt<<" ";
			k-=cnt;
		}
		cnt/=2;
	}
	return ;
}
int bijiao()
{
	int ans=0;
	while(!q.empty() && !p.empty())
	{
		if(q.top() < p.top())
			q.pop();
		else
		if(q.top() > p.top())
			p.pop();
		else
		if(q.top() == p.top())
		{
			ans+=q.top();
			q.pop();
			p.pop();
		}
	}
	while(!p.empty())p.pop();
	while(!q.empty())q.pop();
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sp(a[1]);
	for(int i=2;i<=m;i++)
	{
		sq(a[i]);
		sp(bijiao());
	}
	long long num=0;
	while(!p.empty())
	{
		//cout<<num<<" "<<p.top()<<endl;
		num+=p.top();
		//cout<<p.top()<<" ";
		p.pop();
	}
	cout<<num;
	return 0;
}


