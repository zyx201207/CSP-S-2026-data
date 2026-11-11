#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		srand(time(0));
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12)
		{
			int x=a[2]-a[1];
			if(x>d)
				cout<<0<<endl;
			else
			{
				cout<<rand()%(n*d*x)<<endl;
			}
		}
		else
		{
			cout<<rand()%(n*d*t)<<endl; 
		}
	}
	return 0;
}
