#include <bits/stdc++.h>
using namespace std;
int a,b,n,sum;
int c[10000020];
int main()
{

	int max;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	sort(c+a,c+a+1);
	cout<<c[1]||c[2];
	return 0;
} 
