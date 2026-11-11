#include <bits/stdc++.h>
using namespace std;
int c,T;
long long a[200005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long ans=0;	
		int kkk=a[2]-a[1];
		int num=d/kkk;
		int k=num*2;
		if(n-k+1<0) cout<<0<<endl;
		else cout<<n-k+1<<endl;
		for(int i=1;i<=n;i++) a[i]=0;
	}
	return 0;
}
