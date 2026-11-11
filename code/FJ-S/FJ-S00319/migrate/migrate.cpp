#include<bits/stdc++.h>
using namespace std;
long long a[10000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int round,times;
	cin>>round>>times;
	while(times--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(2*d<a[2]-a[1])
		{
			cout<<0<<endl;
		}else{
			cout<<n-(d/(a[2]-a[1])+d/(a[2]-a[1])-1)<<endl;
	    }
	}	
	return 0;
}