#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<n<<" "<<m<<" "<<m;
	return 0;
}
