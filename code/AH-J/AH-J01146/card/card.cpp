#include<bits/stdc++.h>

using namespace std;
int a[500050];int p[600000]={};
int top=0;
int mfind(int n)
{
	for(int i=0;i<top;i++)
	{
		if(p[i]==n)
		{
			return i;
		}
	}
	return -1;
}
int ans[500050];

int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		
		//bool t[500050]={};
		top=0;
		
		for(int j=i;j<=n;j++)
		{
			int k=mfind(a[j]);
			if(k==-1)
			{
				p[top++]=a[j];
			}
			else
			{
				int u=top;
				for(int i=k+1;i<=u;i++)
				{
					p[i]=0;
					top--;
				}
				top++;
			}
		//	for(int j=0;j<top;j++)
		//{
	//		cout<<p[j];
	//	}
	//	cout<<endl;
		}
		//debug
	//	for(int j=0;j<top;j++)
		//{
			//cout<<p[j];
		//}
		
	//	cout<<endl;
		for(int j=1;j<=m;j++)
		{
			if(mfind(j)>=0)
			{
				ans[j]++;
			}
		}
		//cout<<endl<<endl;
	}
	for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<' ';
		}
	return 0;
}

