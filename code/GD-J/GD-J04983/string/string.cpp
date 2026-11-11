#include <iostream>
using namespace std;
int main()
{
	string a;
	long long n,cnt=0,l=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int no;
		char co;
		cin>>no>>co;
		for(int j=1;j<=no;j++)
		a+=co;
		l+=no;
	}
	for(int i=0;i<=l/2-1;i++)cnt+=(a[i]!=a[l-1-i]);
	cout<<cnt;
	return 0;
}
