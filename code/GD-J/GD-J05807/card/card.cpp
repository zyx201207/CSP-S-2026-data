#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--)
	{
		cin>>a[i];
	}
	n++;
	while(n--)
	{
		for(int i=n;i>=1;i--)
		{
			b[i]=a[i];
			f=0;
			for(int j=i+1;j<=n;j++)
			{
				if(b[i]==b[j]) f=1;
			}
			if(f>0)
			{
				for(int j=i+1;j<=n;j++)
				{
					b[j]=-1;
				}
			}
		}
		for(int i=n;i>=1;i--)
		{
			if(b[i]>0) c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
} 
