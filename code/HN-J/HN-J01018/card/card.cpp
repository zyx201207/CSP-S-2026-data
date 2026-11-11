#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			k++;
			for(int j=i;j<n;j++)
			{
				a[j]=a[j+2];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
