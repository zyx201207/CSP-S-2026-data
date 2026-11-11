#include<bits/stdc++.h>
using namespace std;
int b[10005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0,c,m,maxn,a;
	cin>>c>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		b[i]=a;
		for(int j=1;j<=n;j++)
		{
			n++;
			m=a;
		}
		maxn=max(maxn,a);
	}
	cout<<maxn;
	return 0;
}
