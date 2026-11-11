#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
bool f[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) f[j]=false;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]) for(int k=1;k<=m;k++) f[k]=false; 
			f[a[j]]=true;
		}
		for(int i=1;i<=m;i++) if(f[i]) b[i]++;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
} 
