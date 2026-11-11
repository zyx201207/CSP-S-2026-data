#include<bits/stdc++.h>
using namespace std;
long long c,n,d,t,x[200005],k;
bool b;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(~--t)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		k=(n-1+(n%2-1))/d;
		cout<<k<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
