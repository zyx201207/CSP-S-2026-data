#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		vector<long long>mp(n);
		for(int j=0;j<n;j++)cin>>mp[i];
		cout<<n/3<<endl;
	}
	return 0;
} 
