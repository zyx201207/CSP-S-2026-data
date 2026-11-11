#include<bits/stdc++.h>
using namespace std;
int z,n,a,b,ar[2000006];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>z>>n;
	while(n--)
	{
		cin>>a>>b;
		for(int i = 0;i<a;i++)
		{
			cin>>ar[i];
		}
		if(b<ar[1]-ar[0]) cout<<0<<'\n';
		else cout<<a-b/(ar[1]-ar[0])<<'\n';
	}
	return 0;
}
