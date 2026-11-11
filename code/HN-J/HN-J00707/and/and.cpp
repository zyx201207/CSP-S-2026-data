#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int n,m,sum;
int a[1000000],pre[1000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=m+1;i<=n;i++)
	{
		sum=max(sum,pre[i]-pre[i-m]);
	}
	cout<<sum;
	return 0;
}
