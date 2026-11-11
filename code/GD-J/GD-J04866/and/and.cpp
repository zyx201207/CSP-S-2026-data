#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long max_n;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		max_n=max(max_n,a[i]);
	}
	if(n==1)
	{
		cout<<max_n;
		return 0;
	}else{
		cout<<a[2];
		return 0;
	} 

	return 0;
}
