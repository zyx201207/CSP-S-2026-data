#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long a[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		long long num=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i+3]-a[i]<d*2 && i+3<=n)
			{
				num++;
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
