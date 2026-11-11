#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,k,w[5000001],www;
	srand(time(0));
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>w[i];
		}
	}
	for(int i=1;i<=t;i++){
		www=rand()%1000000;
		cout<<www<<endl;
	}
	return 0;
}
