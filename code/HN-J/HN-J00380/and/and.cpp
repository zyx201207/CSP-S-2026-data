#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
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
	cout<<a[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
