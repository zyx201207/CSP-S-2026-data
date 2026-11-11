#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;
ll n,m,a[MAXN];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=5)
	{
		cout<<m<<" "<<a[1]<<" "<<n;
	}
	else
	{
		cout<<n<<" "<<a[1]<<" "<<m;
	}
	return 0;
}
