#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
short c;
ll t,il[114514],n,d;
int main()
{
	freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	cin>>c>>t;
	for(int z=1;z<=t;z++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>il[i];
		}
		cout<<n/d-1;
	}
	return 0;
}

