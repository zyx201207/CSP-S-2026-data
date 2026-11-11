#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N];
long long b[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m; cin>>n>>m;
	int cnt=0;
	int c=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int j=i;j<=n;j++)
		{
			a[i]-=a[j];
		}
		c++;
		if(a[i]==c) cnt++;
		cout<<cnt;
	}
	return 0;      
}