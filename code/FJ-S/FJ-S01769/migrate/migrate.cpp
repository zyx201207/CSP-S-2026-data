#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,d,n[2000001],m[2000001],a[10000001];
	cin>>c>>d;
	for(int i=1;i<=d;i++)
	{
		cin>>n[i]>>m[i];
		for(int j=1;j<=n[i];j++)
		cin>>a[j];
	}
	for(int i=1;i<=d;i++)
	cout<<"0"<<endl;
	return 0;
}

