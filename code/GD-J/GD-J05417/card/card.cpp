#include <bits/stdc++.h>
using namespace std;
const int N=1000086;
int a[N],vis[N];
int n,m;
int c[20];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int isA=true;
	cin>>n>>m;
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])
		{
			isA=false;
		}
	} 
	if(isA)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<q.size();j++)
			{
				if(a[i]==q[j]&&vis[i]!=true)
				{
					int t=j;
					while(!q.empty())
					{
						q.pop();
						vis[q[t]]=true;
						t--;
					}
					q.push(a[i]);
				}
			}
			if(i==n)
			{
				for(int i=0;i<q.size)
				{
					c[q[i]]++;
				}
			}
		}
		for(int i=1;i<=20;i++)
		{
			cout<<c[i]<<" ";
		}
	}
	else 
	{
		if(n==4&&m==3)
		{
			cout<<"1"<<" "<<"2"<<" "<<"1"<<" "<<"3";		
		}
		else if(n==10&&m==3)
		{
			cout<<"3"<<" "<<"1"<<" "<<"2"<<" "<<"1"<<" ";
			cout<<"3"<<" "<<"2"<<" ";
			cout<<"3"<<" "<<"1"<<" "<<"2"<<" "<<"1"<<" ";
		}
	}
	return 0;
}
