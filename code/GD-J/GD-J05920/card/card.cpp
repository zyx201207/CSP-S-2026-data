#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500005],ans[300005],wz[500005][5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i) 
			{
				wz[i][1]=j;
				break;
			}
		}
		for(int j=n;j>=1;j--)
		{
			if(a[j]==i) 
			{
				wz[i][2]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=wz[a[i]][1];j++) ans[a[j]]++;
		if(i>wz[a[i]][1])
			for(int j=wz[a[i]][2];j<=n;j++) ans[a[j]]++;
		else for(int j=wz[a[i]][2]+1;j<=n;j++) ans[a[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
