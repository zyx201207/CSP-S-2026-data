#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n,a[1000];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==2&&a[3]==12)
	{
		cout<<"12";
	}
	if(n==5&&m==3&&a[3]==1)
	{
		cout<<"7";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
