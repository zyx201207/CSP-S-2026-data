#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
long long n,m,num,k,c,q;
long long a[N],s[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		k=a[2]-a[1];
		if(m>=2*k&&m<3*k) cout<<n-3<<endl;
		else cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
