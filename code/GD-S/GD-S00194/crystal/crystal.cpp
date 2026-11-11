#include<iostream>//20min，应该过了 
#include<algorithm>
using namespace std;
long long n,m,a[500001],s[500001],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1,j=0;i<=n&&j<=n;i++,j++)
	{
		while(j+1<=n&&a[j+1]*(j-i+2)-(s[j+1]-s[i-1])<=m)j++,ans=j-i+1;
	}
	cout<<ans;
	return 0;
}
