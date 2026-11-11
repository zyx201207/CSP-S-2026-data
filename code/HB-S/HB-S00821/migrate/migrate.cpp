#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m,c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>m;
		srand(time(NULL));
		printf("%d\n",rand()%n);
	}
	return 0;
}

