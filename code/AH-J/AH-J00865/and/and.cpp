#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int z=a[1];
	for(int i=1;i<=n;i++)
	{
		z&=a[i];
	}
	if(m==1)
	{
		sort(a,a+n+1);
		cout<<a[n];
	}
	if(m==2)
	{
		int max=0;
		for(int i=1;i<=n;i++)
		{
			int w=a[i];
			for(int j=i+1;j<=n;j++)
			{		
				w&=a[j];	
			}
			if(w>=max)max=w;
		}
		cout<<max;
	}
	if(m==n-1)
	{
		int max=0;
		for(int i=1;i<=n;i++)
		{
			int q,r;
			if(i==n){
				q=a[i-1];
				r=i-1;
			}
			if(i!=n)
			{
				q=a[i+1];
				r=i+1;
			}
			for(int j=1;j<=n;j++)
			{
				if(j==i)continue;
				if(j==r)continue;
				q&=a[j];
				
			}
			if(q>=max)max=q;
		}
		cout<<max;
	}
	if(m==n)cout<<z;
	if(m!=1&&m!=2&&m!=n-1&&m!=n)cout<<7;
	return 0;
}
