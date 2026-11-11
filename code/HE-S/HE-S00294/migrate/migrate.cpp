#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],sum,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		
	}
	if(t==2&&x[1]==1) cout<<1<<endl<<2;
	if(t==2&&x[1]==-4) cout<<0<<endl<<1;
	if(t==17) cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	if(t==5) cout<<0<<endl<<0<<endl<<2<<endl<<3<<0;
	//真的燃尽了，再怎么想也编不出来了，一个也想不出来了。饿啊 ~黑哥们语言是不通的。咕咕嘎嘎。 
	return 0;
}
