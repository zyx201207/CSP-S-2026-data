#include<bits/stdc++.h>
using namespace std;//65
int a[200005],ans[30],vis[30];
int n,m,ma=0;
int cmp(int a,int b)
{
	return a>b;
}
int dfs(int k)
{
	if(k==m)
	{
		int s=ans[0];
		for(int i=1;i<m;i++) s=(s&ans[i]);
		ma=max(ma,s);
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			ans[k]=a[i];
			vis[i]=1;
			dfs(k+1);
			ans[k]=0;
			vis[i]=0;
		}
	}
	return 0;
}
int main()
{
	//freopen("and3.in","r",stdin);
	//freopen("and3.out","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);		
	cin>>n>>m;
	int rp=114514;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(n<=20)
	{
		dfs(0);
		cout<<ma;
		return 0;
	}
	if(m==1)
	{
		cout<<a[0];
		return 0;
	}
	if(m==n)
	{
		int s=a[0];
		for(int i=1;i<n;i++) s=(s&a[i]);
		cout<<s;
		return 0;
	}
	if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	if(a[0]<=4)
	{
		int z=0,x=0,c=0,v=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==2) z++;
			if(a[i]==3) x++;
			if(a[i]==4) c++;
			if(a[i]==1) v++;
		}
		if(c>=m) cout<<4;
		else if(x>=m) cout<<3;
		else if(z+x>=m) cout<<2;
		else if(v+x>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	//¹·¼±ÌøÇ½ 
	int s=a[0];
	for(int i=1;i<m;i++)
	{
		s=(s&a[i]);
	}
	cout<<s;
	return 0;
 } //³õÒ»9AÒª¶öÔÎ£¡£¡£¡¶ö²»Ë¼Êñ£¡£¡£¡ 

 
