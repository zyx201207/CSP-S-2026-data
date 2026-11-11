#include<iostream>
#include<algorithm>
using namespace std;
int a[500001],ans[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int it=upper_bound(a+1,a+1+n,i)-a;
		ans[i]=it-1;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
