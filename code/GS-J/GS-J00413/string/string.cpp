#include<bits/stdc++.h> 
using namespace std;
long long n,sum,ans,b;
const long long MAXN = 1e9;
long long a[MAXN];
string c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum +=a[i];
	}
	if(sum%2 == 0)
	{
		b = n/2+1;
		for(int i=b;i<=n;i++)
		{
			ans +=a[i];
		}
	}
	else
	{
		b = n/2+2;
		for(int i=b;i<=n;i++)
		{
			ans +=a[i];
		}
	}
	cout<<ans;
	return 0;
}
