#include<bits/stdc++.h> 
using namespace std;
int n,m,a,c;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a>c)
		{
			c=a;
		 } 
	}
	cout<<c;
	return 0;
} 
