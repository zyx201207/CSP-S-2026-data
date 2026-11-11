#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200005]; 

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();

	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<a[n-1];
	return 0;
}

