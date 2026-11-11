#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,a[200005],s[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]&a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)cout<<a[n];
	else if(m==n)cout<<s[n];
	else if(m==2)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}	
		} 
		cout<<maxn;
	}
	else if(m==n-1)
	{
		int i=s[n-2]&a[n];
		cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


