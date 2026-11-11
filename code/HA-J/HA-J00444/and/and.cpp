#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[100005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int q=a[i];
		for(int j=i;j<=n;j++)
		{
			if(a[j]>=q)
			{
				int w=q;
				q=a[j];
				a[j]=w;
			}
		}
		a[i]=q;
	}
    cout<<a[m];
	return 0;
}
