#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
long long  n,m,d=0;
//d用来记录最大值 
long long a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1,greater<int>());
	long long ans=1;
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<m+i;j++)
		{
			a[i]=a[i]&a[j];
		 } 
		 ans=max(a[i],ans);
	}
	cout<<ans;
	return 0;
}
