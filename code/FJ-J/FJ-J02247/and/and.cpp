#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	if(x>y) return x<y;
}
long long n,m,x,cnt,a[1000005],max1=INT_MIN;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m+1];
	return 0;
}
