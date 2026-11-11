#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("migrate5.in","r",stdin);
    //freopen("migrate5.out","w",stdout);
	int c,t,n,d,sum=0;
	cin>>c>>t;
	int x[10000];
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			sum+=x[i];
		}
	}
	cout<<sum;
	return 0;
}
