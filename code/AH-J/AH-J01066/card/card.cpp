#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i,ans=0,p;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	p=a[1];
	cout<<n<<" "<<min(n-m,m);;
	return 0;
}
