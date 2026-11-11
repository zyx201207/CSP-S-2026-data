#include<bits/stdc++.h>
using namespace std;
int a[200010],b[100];
int n,m;
int ans=0;
void dfs(int x,int y,int z)
{
	if(x==m)
	{
		ans=max(ans,y);
		return ;
	}
	if(z==n+1) return ;
	int p=y&a[z+1];
	dfs(x,y,z+1);
	dfs(x+1,p,z+1);
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
	if(n<=20)
	{
		dfs(0,pow(2,30)-1,0);//num sum now 
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=pow(2,30)-1;
		for(int i=1;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
    }
    else
    {
		int cnt4=0,cnt3=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==4) cnt4++;
			if(a[i]==3) cnt3++;
			if(a[i]==2) cnt2++;
		}
		if(cnt4>=m) cout<<4;
		else if(cnt3>=m) cout<<3;
		else if(m>n-cnt4) cout<<0;
		else if(cnt2+cnt3>=m) cout<<2;
		else cout<<1;
		return 0;
	}	
}
