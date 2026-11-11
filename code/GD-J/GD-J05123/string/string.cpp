#include<iostream>
using namespace std;
const int maxn=2e5+5;
struct str
{
	int a;
	char b;
}hui[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int sum=0,num=0,ans=0;
	int n,a[maxn]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>hui[i].a>>hui[i].b;
		sum+=hui[i].a;
	}
	sum=sum+1;
	num=sum/2;
	for(int i=1;i<=num;i++)
	{
		if(hui[i].b!=hui[sum-i].b)
		{
			
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
