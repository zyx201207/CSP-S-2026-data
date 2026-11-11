#include<bits/stdc++.h>
using namespace std;
int maxn=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		while(a)
		{
			int a[31];
			a[k]=a%2;
			a=a/2;
			k++;
		}
	}
	return 0;
}
