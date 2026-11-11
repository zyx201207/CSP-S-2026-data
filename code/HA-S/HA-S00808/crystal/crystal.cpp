#include<bits/stdc++.h>
using namespace std;
int s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=1;
	int ls=0,lj=0;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	if(n>=5000)
	{
		int t=0;
		while(ls<=m&&t!=n)
		{
			ls+=s[t];
			t++;
		}
		
		cout<<t<<endl;
		return 0;
	}
	sort(s,s+n);
	for(int i=n-1;i>=0;i--)
	{
		ls=m;
		lj=0;
		for(int j=i;j>=0;j--)
		{
			if(s[i]-s[j]<=ls)
			{
				lj++;
				ls=ls-(s[i]-s[j]);
			}
		}
		maxn=max(maxn,lj);
	}
	cout<<maxn<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
