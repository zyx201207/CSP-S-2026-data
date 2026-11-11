//migrate

#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,d,x[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>x[i];
		int e=m*m;
		if(n/e<1) cout<<0<<"\n";
		else if(n%2) cout<<n/e+1<<"\n";
		else cout<<n/e<<"\n";
	}
}

