#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500001],b[500001],c[500001],s[500001],o;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	  cin>>a[i];
	  
	}
	int top,x,y;
	for(int p=1;p<=n;p++)
	{
		memset(b,0,sizeof(b));
	x=n-p+1;
	y=p;
	top=0;
		for(int i=1;i<=x;i++)
		{
			if(b[a[y]]>0)
			{o=b[a[y]];
				for(int j=o;j<=top;j++)b[s[j]]=0;
				top-=(top-o)+1;
				
			}
			
			s[++top]=a[y++];
			b[s[top]]=top;
		
		}
		for(int i=1;i<=top;i++)
		c[s[i]]++;
	}

	for(int i=1;i<=m;i++)
	cout<<c[i]<<" ";
}

