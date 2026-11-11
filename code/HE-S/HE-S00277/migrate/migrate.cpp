#include<bits/stdc++.h>
using namespace std;
int c,T,a[200005]; 
int main()
{
	//while(1) rp++;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		int n,m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(a[2]-a[1]>m) cout<<0<<endl;
		else cout<<n-4+1<<endl;
	}
	return 0;
}
