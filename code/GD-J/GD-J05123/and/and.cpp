#include<iostream>
using namespace std;
const int maxn=2e5+5;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[maxn],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,a[i-1]^a[i]^a[i-2]);
	}
	cout<<ans;
	return 0;
}
