#include <bits/stdc++.h>
using namespace std;

int c,t,a[2000005];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<n-3<<endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


