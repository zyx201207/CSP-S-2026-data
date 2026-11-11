#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n,p=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{	int a;
		cin>>a;
		if(a>p) p=a;
	}
	cout<<p;
	return 0;
}