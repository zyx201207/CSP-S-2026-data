#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	int a[n];
	sum=n-3;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==sum)
		{
			cout<<a[i];
		}
		
		//kksk 
	}
	return 0;
}


