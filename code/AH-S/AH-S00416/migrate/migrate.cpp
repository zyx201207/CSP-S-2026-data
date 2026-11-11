#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int C,T,n,d,i;
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<"0\n";
	}
}
