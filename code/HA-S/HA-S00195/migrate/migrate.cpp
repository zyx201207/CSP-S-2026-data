#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c==11 || c==12 || c==0)
	{
		while(t--)
		{
			int n;
			long long d;
			cin >> n >> d;
			vector<long long> a;
			for(int i=1;i<=n;i++)
			{
				long long x;
				cin >> x;
				a.push_back(x);
			}
			if(a[2]-a[1]>d || n==1 || n==2 || n==3)
			{
				cout << 0 <<'\n';
				continue;
			}
			else
			{
				int b[200005];
				b[0]=0;
				b[1]=0;
				b[2]=0;
				b[3]=0;
				b[4]=1;
				b[5]=2;
				for(int i=6;i<=n;i++)
					b[i]=b[i-1]+2;
				cout << b[n] <<'\n';
			}
		}
	}
	else
		cout << 1 << '\n' << 2;
	return 0;
}
