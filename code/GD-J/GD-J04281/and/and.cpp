#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[200020][50],b[200020],bm,mx,s,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		mx=max(mx,x);
		while(x>0)
		{
			b[i]++;
			a[i][b[i]]=x%2;
			x=x/2;
		}
		bm=max(bm,b[i]);
	}
	
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	if(m==n)
	{
		s=1;
		ans=0;
		
		for(int i=1;i<=bm;i++)
		{
			int f=1;
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]==0)f=0;
			}
			ans+=f*s;
			s*=2;
		}	
		cout<<ans;
	}
	else if(m==2)
	{
		mx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				s=1;
				ans=0;
				for(int k=1;k<=max(b[i],b[j]);k++)
				{
					if(a[j][k]==1&&a[i][k]==1)ans+=s;
					s*=2;
				}
				mx=max(mx,ans);
			}
			
		}	
		cout<<mx;
	}
	
	return 0;
} 

