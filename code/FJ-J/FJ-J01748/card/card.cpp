#include<bits/stdc++.h>
using namespace std;
stack<int> s;
bool vis[500006];
int n,m;
int a[500006],ans[300006];
void qk(int f)
{
	while(s.top()!=f)
	{
		//cout<<s.top()<<"³öÕ»"<<endl; 
		vis[s.top()]=0;
		s.pop();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				qk(a[j]);
				//cout<<s.top()<<"³öÕ»"<<endl;
				s.pop();
			}
			vis[a[j]]=1;
			s.push(a[j]);
			//cout<<a[j]<<"½øÕ»"<<endl; 
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			//cout<<i<<" "<<s.top()<<endl;
			s.pop();
		}
		for(int j=1;j<=m;j++)
		{
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
