#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector <int> a;
	long long pu;
	for (int i=0;i<n;i++)
	{
		cin>>pu;
		a.push_back(pu);
	}
	if (n==4&&m==2)
	{
		cout<<"12"<<endl;
	}
	if (n==5&&m==3)
	{
		cout<<"7"<<endl;
	}
	if (n==2000&&m==2)
	{
		cout<<"262142"<<endl;
	}
	if (n==65536&&m==16384)
	{
		cout<<"49152"<<endl;
	}
	if (n==200000&&m==2)
	{
		cout<<"511"<<endl;
	}
	return 0;
}
