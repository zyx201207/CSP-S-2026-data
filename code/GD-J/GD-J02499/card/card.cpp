#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[300005],l; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			bool x=0;
			long long y;
			for(int k=1;k<=l;k++)
				if(a[j]==b[k])
				{
					x=1;
					y=k;
					break;
				}
			if(x==0)b[++l]=a[j];
			else
			{
				for(int k=y+1;k<=l;k++)b[k]=0;
				l=y;
			}
		}
		for(int j=1;j<=l;j++)c[b[j]]++;
		for(int j=1;j<=l;j++)b[j]=0;
		l=0;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
} 
