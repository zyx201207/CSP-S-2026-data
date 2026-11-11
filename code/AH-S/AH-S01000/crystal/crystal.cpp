#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a,b;
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]>a[j])
			{
			b[i]=b[i]+(a[i]-a[j]);
			}
			}
			
		}
			
	for(int i=0;i<n;i++)
	{
		if(b[i]==m)
		{
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
