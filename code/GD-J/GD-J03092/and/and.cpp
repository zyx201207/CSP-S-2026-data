#include<iostream>
#include<string>
using namespace std;
unsigned long long n,m,a[300000];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	cout<<a[n/2+1];
	return 0;
}
