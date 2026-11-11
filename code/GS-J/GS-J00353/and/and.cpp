#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	int max=0;
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a;

		for(int j=i;j<=m;j++)
		{
			if((a&tmp)>max)
			{
				max=(a&tmp);
			}

		}
		tmp=a;
	}
	cout<<max;
	return 0;
}
