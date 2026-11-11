#include<iostream>
#include<cstdio>
using namespace std;
long long n;
long long ans;
struct node
{
	long long c;
	char zi;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i].c>>a[i].zi;
	int r=n;
	for(long long i=1;i<r;i++)
	{
		while(a[i].c>=a[r].c)
		{
			if(a[i].zi!=a[r].zi)ans+=a[r].c;
			a[i].c-=a[r].c;
			r--;
		}
		a[r].c-=a[i].c;
		if(a[i].zi!=a[r].zi)ans+=a[i].c;
	}
	cout<<ans;
	return 0;
} 
