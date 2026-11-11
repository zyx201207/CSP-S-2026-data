#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,h=0,t;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2){
	
		for(int i=1;i<=n;i++) 
		{
			for(int j=i+1;j<=n;j++)
			{
				h=max(h,a[i]&a[j]);
			}
		}
	}
	if(m==3){
	
		for(int i=1;i<=n;i++) 
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++)
				{
					h=max(h,a[i]&a[j]&a[z]);
				}
			}
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++)
		{
			h=max(h,a[i]);
		}
	}
	if(m==n){
		h=a[1];
		for(int i=1;i<=n;i++)
		{
			h=h&a[i];
		}
	}
	int q=a[1];
	if(m==n-1){
		for(int i=1;i<=n;i++)
		{
			if(i==1)q=a[2];
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				q=q&a[j];
			}
			h=max(h,q);
			q=a[1];
		}
	}

	

	cout<<h;
}
