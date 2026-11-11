#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define double long double
#define endl "\n"
const int N=2e5+10;
int n,a[N],sum,m,num;
char c[N];
string b;
signed main()
{
	freopen("string.in","r",stdin); freopen("string.out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		sum+=a[i]; 
		for(int j=1;j<=a[i];j++) 
		{
			b[++m]=c[i];
		}
	}
	if(n==1)
	{
		cout << 0;
		return 0;
	}
	if(n==2)
	{
		if(c[1]!=c[2])
		{
			cout << abs(a[1]-a[2])-(a[1]+a[2])%2;
		}
		else
		{
			cout << 0;
		}
	}
	int z=0,y=0;
	for(int i=1;i<=sum/2;i++)
	{
		if(b[sum-i]!=b[i])
		{
			num++;
		}
	}
	cout << num;
	return 0;
}
