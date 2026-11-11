#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long c,t,n,d,x[2000005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(n%d==0 or (n-2)%d==0) cout<<0<<endl;
		else cout<<ceil(n*1.0/d)-1<<endl;
	}
	return 0;	 
} 
