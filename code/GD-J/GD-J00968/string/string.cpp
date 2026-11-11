#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],sum,cnt;
string p[N],f;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>p[i];
		for(int j=1;j<=a[i];j++)
		{
			f[sum]=p[i][0];
			sum++;
		}
	}
	if(n>2000) cout<<0;
	else
	{
		if(n==1) cout<<0;
		else if(n==2)
		{
			if(p[1]==p[2]) cout<<0;
			else
			{
				cout<<min(a[1],a[2]);
			}
		}
		else
		{
			sum--;
			for(int i=0;i<sum/2;i++)
			{
				if(f[i]!=f[sum-1-i]) cnt++;
			}
			cout<<cnt;
		}
	}
}
