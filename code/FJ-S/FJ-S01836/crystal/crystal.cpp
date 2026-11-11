#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[1000001],b[1000001],s[1000001];
long long anss=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[n]-a[i];
		s[i]=s[i-1]+b[i];
	}
	for(int i=n;i>1;i--)
	{
		bool fl=0;
		for(int j=1;j<=n-i+1;j++)
		{
			int k=i;
			int w=s[j+i-1]-s[j-1]-b[j+i-1]*i;
			if(w<=m)
			{
				fl=1;	
				anss=k;
				break;
			}
		}
		if(fl) break;
	}
	cout<<anss;
	return 0;
} 
