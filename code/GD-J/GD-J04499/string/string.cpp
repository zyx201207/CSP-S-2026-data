#include <iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0,num=0;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int y=0;
		char b;
		cin>>y>>b;
		for(int j=k+1;j<=y;j++)
		{
			a[j]=b;
			k++;
		}
	}
	for(int i=1;i<=k/2;i++)
	{
		if(a[i]!=a[k-i+1])
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}
