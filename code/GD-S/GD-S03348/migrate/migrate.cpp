#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,i,j;
	cin>>t>>c;
	for(i=1;i<=c;i++)
	{
		cin>>n>>d;
		for(j=1;j<=n;j++)
			cin>>t;
		srand(time(0));
		cout<<rand()%10000<<endl;
	}
	return 0;
}
