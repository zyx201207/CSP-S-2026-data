#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10,M=1e5+10;
int n,m,a[N],ans[M];
int top,sta[N];
bool v[M]; 

bool chkA()
{
	for(int i=1;i<n;i++)
		if(a[i]>a[i+1])
			return false;
	return true;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(chkA())
	{
		for(int i=1;i<=n;i++)
			ans[a[i]]++;
		for(int i=1;i<=m;i++)
		{
			ans[i]+=ans[i-1];
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	if(m==1&&n>5000)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		top=0;
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]])
			{
				while(sta[top]!=a[j]&&top>0) 
				{
					v[sta[top]]=false;
					top--;
				}
			}
			else 
				sta[++top]=a[j],v[a[j]]=true;
		}
		for(int i=1;i<=m;i++)
			if(v[i])
				ans[i]++,v[i]=false;	
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
