#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
}
    int maxn=-1; 
	for(int i=0;i<m;i++)
	{
		sort(a,a+n);
		a[0]++;
		for(int j=0;j<n;j++)
		{
			long long u=a[j];int o=1;
			for(int y=0;y<n;y++)
			{
				if(j!=y&&a[j]==a[y]) o++;
			}
			maxn=max(maxn,o);
		}
	}
	cout<<maxn<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
