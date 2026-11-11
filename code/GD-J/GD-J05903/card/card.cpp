#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005,MAXM=1e5+5;
int n,m;
int a[MAXN],ans[MAXN],b[MAXM],c[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(b[a[i]]==0)
			b[a[i]]=i;
		else c[i]=b[a[i]];
	}
	for(int i=1;i<=n;i++)
	{
		int d[MAXM]={0};
		for(int j=i;j<=n;j++)
		{
			if(!d[a[j]])
			{
				ans[a[j]]++,d[a[j]]=1;
			}
			if(c[j])j=c[j];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
