#include<bits/stdc++.h>
using namespace std;
char a[100000] ,b[10000];
int n,y,k=1,ans,cnt;
int main()
{
//	freopen("回文串（string）.in","r",stdin);
//	freopen("回文串（string）.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>y;
		char p;
		cin>>p;
		for(int j=1;j<=y;j++)
		{
			a[k]=p;
			k++;
		}
	}
	
	for(int i=1;i<=k/2;i++)
	{
		if(a[i]!=a[k-i+1])ans++;
	}
	if(k%2==0)
	{
		for(int i=k;i>=k/2;i--)
	{
		if(a[i]!=a[k-i+1])cnt++;
	}
	}
	else 
	{
		int f=0;
		for(int i=k;i>=k/2+2;i--)
	{
		f++;
		if(a[i]!=a[f])cnt++;
	}
	}
	int sum=min(ans,cnt);
	cout<<sum;
	return 0;
 } 
