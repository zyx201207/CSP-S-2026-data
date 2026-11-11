#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[500005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		c[i]=b[a[i]];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			
			if(c[j]!=0)j=c[j]-1;
			else d[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<d[i]<<" ";
	return 0;
}
