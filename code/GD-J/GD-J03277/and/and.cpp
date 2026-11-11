#include<bits/stdc++.h>
using namespace std;
long long int n,m;
int a[500005],dfs[500005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
 
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++)
	{
		dfs[i]=a[i]&a[i-1];
	}
	for(int k=2;k<m;k++)
	{
		for(int i=1;i<=n-k;i++)
		{
			int j=i+k;
			for(j=i+k;j<=n;j++)
			{
				dfs[i]=max(dfs[i],dfs[i]&a[j]);
			}
		}
	}
	cout<<dfs[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
