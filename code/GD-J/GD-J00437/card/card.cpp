#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<n<<" "<<m<<" "<<a[1];
	return 0;
}
