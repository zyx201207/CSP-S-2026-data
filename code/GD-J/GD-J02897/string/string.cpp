#include<bits/stdc++.h>
using namespace std;
int a[1001000],h=1,ans=0;
char b[1001000],vis[1001000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(vis[1]==vis[i])
		{
			int l;
		} 
		else
		{
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=h;j<=h+a[i];j++)
		{
			vis[j]=b[i];
		}
		h+=a[i];
		
	}
	if(h%2==0)
	{
		for(int i=1;i<=h/2+1;i++)
		{
			if(vis[i]!=vis[h+1-i])
			{
				ans++;
			}
		}
	}
	else
	{
		for(int i=1;i<=(h+1)/2+1;i++)
		{
			if(vis[i]!=vis[h+1-i])
			{
				ans++;
			}
		}
	}
	
	cout<<ans;
	return 0;
}
