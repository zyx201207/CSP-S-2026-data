#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int a[200010];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=29;i>=0;i--)
	{
		int s=0;
		for(int j=1;j<=n;j++)
			s+=(a[j]>>i)&1;
		if(s>=m)
		{
			t+=1<<i;
			int N=0;
			for(int j=1;j<=n;j++)
				if((a[j]>>i)&1)
					a[++N]=a[j];
			n=N;
		}
	}
	cout<<t;
	return 0;
}

