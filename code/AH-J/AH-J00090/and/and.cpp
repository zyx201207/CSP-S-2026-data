#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],s[200001],ss[200001];
int mx;
void dfs(int id,int k,int ans)
{
	if(ans==0) return;
	if(id>n&&k<m) return;
	if(k==m) 
	{
		mx=max(ans,mx);
		return;
	}
	for(int i=id+1;i<=n;i++)
	{
		dfs(i,k+1,ans&a[i]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool t=true;
	cin>>n>>m;
	cin>>a[1];
	s[1]=a[1];
	cin>>a[2];
	ss[2]=a[2];
	s[2]=a[1]&a[2];
	mx=max(a[1],a[2]);
	for(int i=3;i<=n;i++)
	{
		cin>>a[i];
		if(t)
		{
			bool tt=false;
			for(int j=1;j<30;j++)
			{
				if(pow(2,i)==a[i]+1)
				{
					tt=true;
					break;
				}
			}
			if(tt=false) t=false;
		}
		s[i]=s[i-1]&a[i];
		ss[i]=ss[i-1]&a[i];
		mx=max(a[i],mx);
	}
	if(m==n)
	{
		cout<<s[n];
		return 0;
	}
	if(m==n-1)
	{
		cout<<max(s[n-1],ss[n]);
		return 0;
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	if(t=true)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	mx=0;
	for(int i=1;i<=n;i++)
		dfs(i,1,a[i]);
	cout<<mx;
	return 0;
}
