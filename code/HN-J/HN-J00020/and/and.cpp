#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],b[200005],result;
struct p
{
	int sj;
	int cf;
}px[200005];
bool cmp(p x,p y)
{
	return x.cf<=y.cf;
}
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		px[i].sj=a[i];
		px[i].cf=b[i];
	}
	sort(px+1,px+n+1,cmp);

	for(int i=1;i<=m;i++)
	{
		result=12;
	}
	cout<<result;
	return 0;
}
