#include<iostream> 
using namespace std;
unsigned long long n,m,a[200005],ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1) ans=a[1];
		else ans=ans&a[i];
	}
	if(n==m)
	{
		cout<<ans;
		return 0;
	}
	ans=0;
	return 0;
}
