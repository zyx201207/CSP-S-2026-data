#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<n<<a[1]<<m;
	return 0;
}
