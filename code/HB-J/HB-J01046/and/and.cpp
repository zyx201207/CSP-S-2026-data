#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int a[200005];
int main()
{
	//KSKBL ZDJD?
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,Max;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	Max=a[0];
	for(int i=0;i<m;i++)
	{
		Max=Max & a[i];
	}
	cout<<Max;
	return 0;
}
