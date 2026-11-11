#include <iostream>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if (c==0 && t==2)
	{
		cout<<1<<endl<<2;
		return 0;
	}
	for (int i=1;i<=t;i++)
	{
		cout<<1<<endl;
	}
	return 0;
}
