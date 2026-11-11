#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],k[10000000],ans;
int p=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int max=-1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		for(int j=i;j<=m;j++)
		{
			k[j]=(a[j]%2/2)*p;
			ans=k[j]&&k[j+1];
			if(ans>max)
			{
				max=ans;
			}
			p*=2;
		}
	}
	cout << max;
	return 0;
}
