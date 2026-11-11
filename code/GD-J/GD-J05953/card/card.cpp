#include<bits/stdc++.h>
using namespace std;
long long n,m; 
int t;
int a[1000005],b[1000005],c[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		t=1;
		for(int j=i;j<=n;j++)
		{
			b[a[j]]++;
			if(b[a[j]]>1)t=j,b[a[j]]=1;
		}
		memset(b,0,sizeof(b));
		for(int j=max(t,i);j<=n;j++)
		{
			b[a[j]]++;
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j]>0)c[j]++;
		} 
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
