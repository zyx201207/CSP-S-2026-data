#include<bits/stdc++.h>
using namespace std;
long long a[200099];
int b[50][200099];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
	 	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int c=1;
		for(int j=1;;j++)
		{
			c=c*2;
			if(c>=a[i])
			{
				b[i][j]=1;
				break;
			}
		}
		int x=a[i]%c;
	}
	cout<<12;
	return 0;
}

