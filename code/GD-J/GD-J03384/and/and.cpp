#include <iostream> 
#include <algorithm>
using namespace std;
#define int long long
int n,m,a[1000008];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(a[1]==a[n])
	{
		cout<<a[1];
		fclose(stdin);
	    fclose(stdout);
	}
	int sum=a[1];
	for(int i=1;i<=m;i++)
	{
		sum=sum&a[i];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
}
