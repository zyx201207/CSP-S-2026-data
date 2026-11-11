#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=3;i--)
	{
		int s=a[i];
		for(int j=i-1;j>=i-m;j--)
		{
			s=s&a[j];
		}
		if(s>k) k=s;
	}
	cout<<k;
return 0;
}
