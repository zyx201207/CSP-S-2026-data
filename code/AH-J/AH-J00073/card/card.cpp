#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int a[5*N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",a+i);
	}
	cout<<n<<" ";
	for(int i=1; i<=m-1; i++)
	 cout<<2<<" ";
	return 0;
} 
