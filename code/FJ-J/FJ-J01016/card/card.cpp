#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++)
	{
		cin>>a[n];
	}
	for(int i=0;i<n;i++)
	{
		int pd[n];
		for(int j=0;j<n;j++)
		{
			if(j+i>n)
			{
				pd[j]=a[i+j-n];
			}
			else
			{
				pd[j]=a[i+j];
			
			}
		}
	}
	cout<<n<<" "<<n<<" "<<n<<" ";
	return 0;
}
