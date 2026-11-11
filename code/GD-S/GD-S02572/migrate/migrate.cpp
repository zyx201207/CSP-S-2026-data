#include<bits/stdc++.h>
using namespace std;
int c,n,d,t;
long long r;
long long a[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		if(n<4) cout<<0;
		if(n==4) cout<<1;
		else{
			cout<<1+(n-4)*2;
		}
		cout<<endl;
	}
	return 0;
}
