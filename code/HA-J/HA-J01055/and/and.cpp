#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
long long a[100000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[n];
	for(int i=2;i<=m;i++)
	{
		n--;
		sum&=a[n];
	}
	cout<<sum;
	return 0;
}
